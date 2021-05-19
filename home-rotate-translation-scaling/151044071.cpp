#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
int xPos = 0;
float translate_posx = 0;
float translate_posy = 0;
float translate_posz = 0;
float scale = 1.0f;
float _Y_angle = 0.0f;
float _angle = -45.0f;
float cameraAngleDegree = 0.0f;
using namespace std;


void initilization_Rendering() {
    glEnable(GL_DEPTH_TEST);
}
void handle_Resize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double) w / (double) h, 1.0, 200.0);
}


void drawHouseWithScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-cameraAngleDegree, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.0f, -1.5f, -2.0f);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 0.0f);
    glRotatef(_angle, _Y_angle, 1.0f, 0.0f);
    glTranslatef(translate_posx, translate_posy, 0.0f);
    glScalef(scale, scale, scale);
    glColor3f(1.0, 0.25, 1.0);
    glColor3f (.5, 0.5, .25);

    /* main rec */
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.35f);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glEnd();

    /*back rec*/
    glColor3f(1.0f,0.0f,0.35f);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    /* left rec */
    glColor3f(1.0f,0.0f,0.55f);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    /* right rec */
    glColor3f(1.0f,0.0f,0.45f);
    glBegin(GL_POLYGON);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glEnd();

    /* left tri */
    glColor3f (.5, 0.5, .35);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.9, 0.8, 0.25);
    glEnd();

    /* right tri */
    glColor3f (.5, 0.5, .35);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /* roof */
    glColor3f (.55, 0.35, .3);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /*back roof */
    glColor3f (.55, 0.35, .3);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.9, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /* door */
    glColor3f (.3, 0.15, .2);
    glBegin(GL_POLYGON);
    glVertex3f (0.47, 0.105, 0.0);
    glVertex3f (0.65, 0.105, 0.0);
    glVertex3f (0.65, 0.46, 0.0);
    glVertex3f (0.47, 0.46, 0.0);
    glEnd();

    /* window 1 */
    glColor3f (.3, 0.2, .2);
    glBegin(GL_POLYGON);
    glVertex3f (0.72, 0.25, 0.0);
    glVertex3f (0.83, 0.25, 0.0);
    glVertex3f (0.83, 0.4, 0.0);
    glVertex3f (0.72, 0.4, 0.0);
    glEnd();

    /* window 2 */
    glColor3f (.3, 0.2, .2);
    glBegin(GL_POLYGON);
    glVertex3f (0.27, 0.25, 0.0);
    glVertex3f (0.38, 0.25, 0.0);
    glVertex3f (0.38, 0.4, 0.0);
    glVertex3f (0.27, 0.4, 0.0);
    glEnd();


    glFlush ();
    glPopMatrix();
    glutSwapBuffers();
}
void processSpecialKeys(int key,int x,int y)
{

	switch (key)
  	{
	case GLUT_KEY_END :
		exit(0);
	      break;
	case GLUT_KEY_LEFT :

	      translate_posx += 1;
	 glutPostRedisplay();
	      break;
	case GLUT_KEY_RIGHT :

	      translate_posx -= 1;
	 glutPostRedisplay();
	    break;
	case GLUT_KEY_UP :

	     translate_posy += 1;
	 glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN :

	      translate_posy -= 1;
	 glutPostRedisplay();
		break;
	case GLUT_KEY_F1 :


	   scale += 0.2;
	    glutPostRedisplay();
		break;
	case GLUT_KEY_F2 :


	   scale -= 0.2;
	    glutPostRedisplay();
		break;
	case GLUT_KEY_F3 :
	   _angle +=1.0;
	  if (_angle > 360) {
		_angle -= 360;
	    }
	    glutPostRedisplay();
		break;
	case GLUT_KEY_F4 :
	   _angle -=1.0;
	  if (_angle > 360) {
		_angle -= 360;
	    }
	    glutPostRedisplay();
		break;
	case GLUT_KEY_F5 :
	   _Y_angle +=1.0;
	  if (_angle > 360) {
		_angle -= 360;
	    }
	    glutPostRedisplay();
		break;
	case GLUT_KEY_F6 :
	   _Y_angle -=1.0;
	  if (_angle > 360) {
		_angle -= 360;
	    }
	    glutPostRedisplay();
		break;

}
}

int main(int argc, char * * argv) {
    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("3D House");
    initilization_Rendering();
    glutDisplayFunc(drawHouseWithScene);
    glutSpecialFunc(processSpecialKeys);
    glutReshapeFunc(handle_Resize);
    glutMainLoop();
    return 0;
}
