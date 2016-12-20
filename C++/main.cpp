#include "FractalDFS/FractalDFS.hpp"
#include "FractalRecipes/Classic/Classic.hpp"
#include "FractalRecipes/Yourgens/Yourgens.hpp"
#include "FractalRecipes/Reily/Reily.hpp"
#include "FractalRecipes/Maskit/Maskit.hpp"

uint level;
ldouble epsilon;

static void display()
{
    ldouble ar, ai, br, bi;

    ar = 1.886;
    ai = 0.05;
    br = 2;
    bi = 0;


    std::unique_ptr<FractalRecipe> fr(new ClassicRecipe(ar, ai, br, bi));
    FractalDFS fc(fr, level, epsilon, "p");

    gluOrtho2D(-1, 1, -1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
        fc.render_fractal_recurs();
    glFlush();

    fc.info();
}

int main(int argc, char** argv)
{
    char i[20];
    std::cout << "Number : ";
    std::cin >> i;

    char title[128];
    sprintf(title, "Fractal Render 1.0 : Group Number %s.", i);

    std::cout << "MAX Level : ";
    std::cin >> level;

    std::cout << "Epsilon : ";
    std::cin >> epsilon;

    glutInit(&argc, argv); // Initialize GLUT
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(250, 250); // Position the window's initial top-left corner
    glutCreateWindow(title); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the infinitely event-processing loop

    return 0;
}