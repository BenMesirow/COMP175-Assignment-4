#define NUM_OPENGL_LIGHTS 8

#include <iostream>
#include <fstream>
#include <string>
#include <GL/glui.h>
#include "Shape.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Sphere.h"
#include "SceneParser.h"
#include "Camera.h"

using namespace std;

/** These are the live variables passed into GLUI ***/
int  isectOnly = 1;
int staticID;
struct sceneElement{
	Matrix  t;
	int*    s;
	SceneMaterial* m;
};

sceneElement* sceneData = NULL;

int	 camRotU = 0;
int	 camRotV = 0;
int	 camRotW = 0;
int  viewAngle = 45;
float eyeX = 2;
float eyeY = 2;
float eyeZ = 2;
float lookX = -2;
float lookY = -2;
float lookZ = -2;

/** These are GLUI control panel objects ***/
int  main_window;
string filenamePath = "data/general/test.xml";
GLUI_EditText* filenameTextField = NULL;
GLubyte* pixels = NULL;
int pixelWidth = 0, pixelHeight = 0;
int screenWidth = 0, screenHeight = 0;

/** these are the global variables used for rendering **/
Cube* cube = new Cube();
Cylinder* cylinder = new Cylinder();
Cone* cone = new Cone();
Sphere* sphere = new Sphere();
SceneParser* parser = NULL;
Camera* camera = new Camera();


void setupCamera();
void updateCamera();

void setPixel(GLubyte* buf, int x, int y, int r, int g, int b) {
	buf[(y*pixelWidth + x) * 3 + 0] = (GLubyte)r;
	buf[(y*pixelWidth + x) * 3 + 1] = (GLubyte)g;
	buf[(y*pixelWidth + x) * 3 + 2] = (GLubyte)b;
}

void callback_start(int id) {
	cout << "start button clicked!" << endl;

	if (parser == NULL) {
		cout << "no scene loaded yet" << endl;
		return;
	}

	pixelWidth = screenWidth;
	pixelHeight = screenHeight;

	updateCamera();

	if (pixels != NULL) {
		delete pixels;
	}
	pixels = new GLubyte[pixelWidth  * pixelHeight * 3];
	memset(pixels, 0, pixelWidth  * pixelHeight * 3);

	cout << "(w, h): " << pixelWidth << ", " << pixelHeight << endl;

	Point eyePoint = Point(eyeX, eyeY, eyeZ);
	SceneGlobalData global;
	parser->getGlobalData(global);

	float ka = global.ka;
	float kd = global.kd;
	int nLights = parser->getNumLights();

	int half_width = pixelWidth / 2;
	int half_height = pixelHeight / 2;

	Vector look = camera->GetLookVector();

	for (int i = 0; i < pixelWidth; i++) {
		float angleX = viewAngle * (i - half_width) / half_width;
		Matrix Mrotx = rotX_mat(DEG_TO_RAD(angleX));
		for (int j = 0; j < pixelHeight; j++) {

			float angleY = viewAngle * (half_height - j) / half_height;
			Vector d = rotY_mat(DEG_TO_RAD(angleY)) * Mrotx * look;

			if ((i % 5 == 0) && (j % 5 == 0)) {
				if (isectOnly)
					setPixel(pixels, i, j, 255, 255, 255);
				else
					//test to see if angleX is correct;
					//setPixel(pixels, i, j, 255, 255 * abs(angleX) / viewAngle, 0);
					//test to see if angleY is correct;
					//setPixel(pixels, i, j, 255, 0, 255 * abs(angleY) / viewAngle);
					setPixel(pixels, i, j, 255, 255 * abs((int)angleX) / viewAngle, 255 * abs((int)angleY) / viewAngle);
			}

			else {
				setPixel(pixels, i, j, 0, 0, 0);
			}
		}
	}
	glutPostRedisplay();
}

void parseAndFill(SceneNode *node, Matrix& fromP, sceneElement* sceneData) {
	if (node != NULL) {
		Matrix T = fromP;
		for (int i = 0; i < node->transformations.size(); i++) {
			switch(node->transformations[i]->type) {
				case TRANSFORMATION_TRANSLATE:
					T = T * trans_mat(node->transformations[i]->translate);
					break;
				case TRANSFORMATION_SCALE:
					T = T * scale_mat(node->transformations[i]->scale);
					break;
				case TRANSFORMATION_ROTATE:
					T = T * rot_mat(node->transformations[i]->rotate, node->transformations[i]->angle);
					break;
				case TRANSFORMATION_MATRIX:
					T = T * node->transformations[i]->matrix;
					break;
			}
		}

		sceneData[staticID].t = T; 


		(sceneData[staticID].s)[0] = node->primitives.size();
		for (int i = 0; i < node->primitives.size(); i++) {
				(sceneData[staticID].s)[i+1] = node->primitives[i]->type;
				(sceneData[staticID].m)[i]   = node->primitives[i]->material;
		}

		for (int i = 0; i < node->children.size(); i++) {
			staticID++;
			parseAndFill(node->children[i], T, sceneData);
		}
	}
}

void callback_load(int id) {
	char curDirName [2048];
	if (filenameTextField == NULL) {
		return;
	}
	printf ("%s\n", filenameTextField->get_text());

	if (parser != NULL) {
		delete parser;
	}
	parser = new SceneParser (filenamePath);
	SceneNode*     root = parser->getRootNode();
	cout << "success? " << parser->parse() << endl;

	sceneData = new sceneElement[1000];

	for(int i =0; i < 1000; i++){
		sceneData[i].s = new int[100];
		sceneData[i].m = new SceneMaterial[100];
	}

	Matrix I = Matrix();
	staticID = 0;
	parseAndFill(root, I, sceneData);

	setupCamera();
}

/***************************************** myGlutIdle() ***********/

void myGlutIdle(void)
{
	/* According to the GLUT specification, the current window is
	undefined during an idle callback.  So we need to explicitly change
	it if necessary */
	if (glutGetWindow() != main_window)
		glutSetWindow(main_window);

	glutPostRedisplay();
}


/**************************************** myGlutReshape() *************/

void myGlutReshape(int x, int y)
{
	float xy_aspect;

	xy_aspect = (float)x / (float)y;
	glViewport(0, 0, x, y);
	camera->SetScreenSize(x, y);

	screenWidth = x;
	screenHeight = y;

	glutPostRedisplay();
}


/***************************************** setupCamera() *****************/
void setupCamera()
{
	SceneCameraData cameraData;
	parser->getCameraData(cameraData);

	camera->Reset();
	camera->SetViewAngle(cameraData.heightAngle);
	if (cameraData.isDir == true) {
		camera->Orient(cameraData.pos, cameraData.look, cameraData.up);
	}
	else {
		camera->Orient(cameraData.pos, cameraData.lookAt, cameraData.up);
	}

	viewAngle = camera->GetViewAngle();
	Point eyeP = camera->GetEyePoint();
	Vector lookV = camera->GetLookVector();
	eyeX = eyeP[0];
	eyeY = eyeP[1];
	eyeZ = eyeP[2];
	lookX = lookV[0];
	lookY = lookV[1];
	lookZ = lookV[2];
	camRotU = 0;
	camRotV = 0;
	camRotW = 0;
	GLUI_Master.sync_live_all();
}

void updateCamera()
{
	camera->Reset();

	Point guiEye (eyeX, eyeY, eyeZ);
	Point guiLook(lookX, lookY, lookZ);
	camera->SetViewAngle(viewAngle);
	camera->Orient(guiEye, guiLook, camera->GetUpVector());
	camera->RotateU(camRotU);
	camera->RotateV(camRotV);
	camera->RotateW(camRotW);
}

/***************************************** myGlutDisplay() *****************/

void myGlutDisplay(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (parser == NULL || pixels == NULL) {
		return;
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glDrawPixels(pixelWidth, pixelHeight, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	glutSwapBuffers();
}

void onExit()
{
	delete cube;
	delete cylinder;
	delete cone;
	delete sphere;
	delete camera;
	if (parser != NULL) {
		delete parser;
	}
	if (pixels != NULL) {
		delete pixels;
	}
}

/**************************************** main() ********************/

int main(int argc, char* argv[])
{
	atexit(onExit);

	/****************************************/
	/*   Initialize GLUT and create window  */
	/****************************************/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);

	main_window = glutCreateWindow("COMP 175 Assignment 4");
	glutDisplayFunc(myGlutDisplay);
	glutReshapeFunc(myGlutReshape);

	/****************************************/
	/*         Here's the GLUI code         */
	/****************************************/

	GLUI* glui = GLUI_Master.create_glui("GLUI");

	filenameTextField = new GLUI_EditText( glui, "Filename:", filenamePath);
	filenameTextField->set_w(300);
	glui->add_button("Load", 0, callback_load);
	glui->add_button("Start!", 0, callback_start);
	glui->add_checkbox("Isect Only", &isectOnly);
	
	GLUI_Panel *camera_panel = glui->add_panel("Camera");
	(new GLUI_Spinner(camera_panel, "RotateV:", &camRotV))
		->set_int_limits(-179, 179);
	(new GLUI_Spinner(camera_panel, "RotateU:", &camRotU))
		->set_int_limits(-179, 179);
	(new GLUI_Spinner(camera_panel, "RotateW:", &camRotW))
		->set_int_limits(-179, 179);
	(new GLUI_Spinner(camera_panel, "Angle:", &viewAngle))
		->set_int_limits(1, 179);

	glui->add_column_to_panel(camera_panel, true);

	GLUI_Spinner* eyex_widget = glui->add_spinner_to_panel(camera_panel, "EyeX:", GLUI_SPINNER_FLOAT, &eyeX);
	eyex_widget->set_float_limits(-10, 10);
	GLUI_Spinner* eyey_widget = glui->add_spinner_to_panel(camera_panel, "EyeY:", GLUI_SPINNER_FLOAT, &eyeY);
	eyey_widget->set_float_limits(-10, 10);
	GLUI_Spinner* eyez_widget = glui->add_spinner_to_panel(camera_panel, "EyeZ:", GLUI_SPINNER_FLOAT, &eyeZ);
	eyez_widget->set_float_limits(-10, 10);

	GLUI_Spinner* lookx_widget = glui->add_spinner_to_panel(camera_panel, "LookX:", GLUI_SPINNER_FLOAT, &lookX);
	lookx_widget->set_float_limits(-10, 10);
	GLUI_Spinner* looky_widget = glui->add_spinner_to_panel(camera_panel, "LookY:", GLUI_SPINNER_FLOAT, &lookY);
	looky_widget->set_float_limits(-10, 10);
	GLUI_Spinner* lookz_widget = glui->add_spinner_to_panel(camera_panel, "LookZ:", GLUI_SPINNER_FLOAT, &lookZ);
	lookz_widget->set_float_limits(-10, 10);

	glui->add_button("Quit", 0, (GLUI_Update_CB)exit);

	glui->set_main_gfx_window(main_window);

	/* We register the idle callback with GLUI, *not* with GLUT */
	GLUI_Master.set_glutIdleFunc(myGlutIdle);

	glutMainLoop();

	return EXIT_SUCCESS;
}



