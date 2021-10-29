#include "graphics.h"
#include "Button.h"
#include "circle.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <GLUT/glut.h>
#include <math.h>
#define PI 3.14159265f
using namespace std;

GLdouble width, height;
int wd;
Button Red({0.6, 0, 0}, {250, 100}, 250, 100, "Red");
Button Blue({0, 0, 0.6}, {250, 250}, 250, 100, "Blue");
Button Green({0, 0.4, 0}, {250, 400}, 250, 100, "Green");
Circle ball;
GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

void init() {
    width = 500;
    height = 500;
    srand(time(0));
}

// initialize ball
void initCircle() {
    ball.setRadius(0.1);
    ball.setBallX(0.0);
    ball.setBallY(0.0);
    ball.setSpeedX(0.02);
    ball.setSpeedY(0.008);
}
/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.95f, 0.83f, 0.40f, 1.0f);
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width * 2, height * 2);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    Red.draw();
    Blue.draw();
    Green.draw();

    glFlush();
}

// red screen
void red() {
    glClearColor(0.99, 0.80, 0.80, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(ball.getBallX(), ball.getBallY(), 0.0f);
    glViewport(0, 0, width * 2, height * 2);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    int numSegments = 100;
    GLfloat angle;
    for (int i = 0; i <= numSegments; i++) {
        angle = i * 2.0f * PI / numSegments;
        glVertex2f(cos(angle) * ball.getRadius(), sin(angle) * ball.getRadius());
    }
    glEnd();

    glutSwapBuffers();

    ball.setBallX(ball.getBallX() + ball.getSpeedX());
    ball.setBallY(ball.getBallY() + ball.getSpeedY());

    // check if the ball exceeds the edges
    if (ball.getBallX() > ball.getBallXmax()) {
        ball.setBallX(ball.getBallXmax());
        ball.setSpeedX(-ball.getSpeedX());
    } else if (ball.getBallX() < ball.getBallXmin()) {
        ball.setBallX(ball.getBallXmin());
        ball.setSpeedX(-ball.getSpeedX());
    }
    if (ball.getBallY() > ball.getBallYmax()) {
        ball.setBallY(ball.getBallYmax());
        ball.setSpeedY(-ball.getSpeedY());
    } else if (ball.getBallY() < ball.getBallYmin()) {
        ball.setBallY(ball.getBallYmin());
        ball.setSpeedY(-ball.getSpeedY());
    }

    // allows user to go back to main screen
    glRasterPos2d(35, 150);
    for (const char &letter : "Press 'b' to go back to the colors screen") {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glutKeyboardFunc(kbd);

    // handles special keys
    glutSpecialFunc(kbdS);
}

// blue screen
void blue() {
    glClearColor(0.80, 0.80, 0.99, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(ball.getBallX(), ball.getBallY(), 0.0f);
    glViewport(0, 0, width * 2, height * 2);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    int numSegments = 100;
    GLfloat angle;
    for (int i = 0; i <= numSegments; i++) {
        angle = i * 2.0f * PI / numSegments;
        glVertex2f(cos(angle) * ball.getRadius(), sin(angle) * ball.getRadius());
    }
    glEnd();

    glutSwapBuffers();

    ball.setBallX(ball.getBallX() + ball.getSpeedX());
    ball.setBallY(ball.getBallY() + ball.getSpeedY());

    // check if the ball exceeds the edges
    if (ball.getBallX() > ball.getBallXmax()) {
        ball.setBallX(ball.getBallXmax());
        ball.setSpeedX(-ball.getSpeedX());
    } else if (ball.getBallX() < ball.getBallXmin()) {
        ball.setBallX(ball.getBallXmin());
        ball.setSpeedX(-ball.getSpeedX());
    }
    if (ball.getBallY() > ball.getBallYmax()) {
        ball.setBallY(ball.getBallYmax());
        ball.setSpeedY(-ball.getSpeedY());
    } else if (ball.getBallY() < ball.getBallYmin()) {
        ball.setBallY(ball.getBallYmin());
        ball.setSpeedY(-ball.getSpeedY());
    }

    // allows user to go back to main screen
    glRasterPos2d(35, 150);
    for (const char &letter : "Press 'b' to go back to the colors screen") {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glutKeyboardFunc(kbd);

    // handles special keys
    glutSpecialFunc(kbdS);
}

// green screen
void green() {
    glClearColor(0.80, 0.99, 0.80, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(ball.getBallX(), ball.getBallY(), 0.0f);
    glViewport(0, 0, width * 2, height * 2);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.4f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    int numSegments = 100;
    GLfloat angle;
    for (int i = 0; i <= numSegments; i++) {
        angle = i * 2.0f * PI / numSegments;
        glVertex2f(cos(angle) * ball.getRadius(), sin(angle) * ball.getRadius());
    }
    glEnd();

    glutSwapBuffers();

    ball.setBallX(ball.getBallX() + ball.getSpeedX());
    ball.setBallY(ball.getBallY() + ball.getSpeedY());

    // check if the ball exceeds the edges
    if (ball.getBallX() > ball.getBallXmax()) {
        ball.setBallX(ball.getBallXmax());
        ball.setSpeedX(-ball.getSpeedX());
    } else if (ball.getBallX() < ball.getBallXmin()) {
        ball.setBallX(ball.getBallXmin());
        ball.setSpeedX(-ball.getSpeedX());
    }
    if (ball.getBallY() > ball.getBallYmax()) {
        ball.setBallY(ball.getBallYmax());
        ball.setSpeedY(-ball.getSpeedY());
    } else if (ball.getBallY() < ball.getBallYmin()) {
        ball.setBallY(ball.getBallYmin());
        ball.setSpeedY(-ball.getSpeedY());
    }

    // allows user to go back to main screen
    glRasterPos2d(35, 150);
    for (const char &letter : "Press 'b' to go back to the colors screen") {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glutKeyboardFunc(kbd);

    // handles special keys
    glutSpecialFunc(kbdS);
}

// keyboard input to change ball speed and size
void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            ball.size(false);
            break;
        case GLUT_KEY_LEFT:
            ball.speed(false);
            break;
        case GLUT_KEY_RIGHT:
            ball.speed(true);
            break;
        case GLUT_KEY_UP:
            ball.size(true);
            break;
    }

    glutPostRedisplay();
}

// keyboard input to go back to main screen
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    else if (key == 'b'){
        wd = glutCreateWindow("Color Screen" /* title */ );
        glutDisplayFunc(display);
        glutKeyboardFunc(kbd);
        glutPassiveMotionFunc(cursor);
        glutMouseFunc(mouse);
    }

    glutPostRedisplay();
}

// changes button color when cursor hovers over it
void cursor(int x, int y) {
    if (Red.isOverlapping(x, y)) {
        Red.hover();
    }
    else {
        Red.release();
    }
    if (Blue.isOverlapping(x, y)) {
        Blue.hover();
    }
    else {
        Blue.release();
    }
    if (Green.isOverlapping(x, y)) {
        Green.hover();
    }
    else {
        Green.release();
    }
    glutPostRedisplay();
}

// mouse inputs for clicking on the different colors
void mouse(int button, int state, int x, int y) {
    if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && Red.isOverlapping(x, y)) {
        Red.pressDown();
        wd = glutCreateWindow("Red Screen" /* title */);
        glutDisplayFunc(red);
        glutPassiveMotionFunc(cursor);
        glutMouseFunc(mouse);
    }
    else {
        Red.release();
    }

    if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && Blue.isOverlapping(x, y)) {
        Blue.pressDown();
        wd = glutCreateWindow("Blue Screen" /* title */);
        glutDisplayFunc(blue);
        glutPassiveMotionFunc(cursor);
        glutMouseFunc(mouse);
    }
    else {
        Blue.release();
    }

    if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && Green.isOverlapping(x, y)) {
        Green.pressDown();
        wd = glutCreateWindow("Green Screen" /* title */);
        glutDisplayFunc(green);
        glutPassiveMotionFunc(cursor);
        glutMouseFunc(mouse);
    }
    else {
        Red.release();
    }

    glutPostRedisplay();
}


// keeps the ball from leaving the boundary of the screen
void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width * 2, height * 2);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (width >= height) {
        clipAreaXLeft = -1.0 * aspect;
        clipAreaXRight = 1.0 * aspect;
        clipAreaYBottom = -1.0;
        clipAreaYTop = 1.0;
    } else {
        clipAreaXLeft = -1.0;
        clipAreaXRight = 1.0;
        clipAreaYBottom = -1.0 / aspect;
        clipAreaYTop = 1.0 / aspect;
    }
    gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
    ball.setBallXmin(clipAreaXLeft + ball.getRadius());
    ball.setBallXmax(clipAreaXRight - ball.getRadius());
    ball.setBallYmin(clipAreaYBottom + ball.getRadius());
    ball.setBallYmax(clipAreaYTop - ball.getRadius());
}

void timer(int dummy) {
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    initCircle();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Ball Color Screen" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // handles special keys
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // reshape function
    glutReshapeFunc(reshape);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
