#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cstdio>

const int gridSize = 32;

const int SCREEN_WIDTH = gridSize*32;
const int SCREEN_HEIGHT = gridSize*16;

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main() {
    GLFWwindow* window;
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT,"Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glColor3d(1.0, 0.0, 0.0);


        glOrtho(0, width, height, 0, 0, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        //attempt to draw lines
        glBegin(GL_LINES);
        //horizontal
        for (int i = 0; i < SCREEN_HEIGHT; i+=gridSize){
            glVertex2f(0, i);
            glVertex2f(SCREEN_WIDTH,i);
        }
        //vertical
        for (int i = 0; i < SCREEN_WIDTH; i += gridSize){
            glVertex2f(i,0);
            glVertex2f(i, SCREEN_HEIGHT);
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
