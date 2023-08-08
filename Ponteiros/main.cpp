#include <iostream>

using namespace std;

int main() {
    int   x = 30;
    float y = 0.625;
    char  z = 'a';

    // Os ponteiros são do mesmo tipo da variável que eles apontam.
    // Uma das formas de declarar um ponteiro

    int   *px = &x;
    float *py = &y;
    char  *pz = &z;

    /* Outra forma de declarar ponteiros;
    // int *px;
    // px = &x;
    */

    cout << x << " " << *px << "\n";
    cout << "Endereco de X: " << px << " Valor de X: " << *px << "\n\n";

    cout << y << " " << *py << "\n";
    cout << "Endereco de Y: " << py << " Valor de Y: " << *py << "\n\n";

    // Foi necessario fazer um cast porque o ponteiro é do tipo char
    cout << z << " " << *pz << "\n";
    cout << "Endereco de Z: " << static_cast<void*>(pz) << " Valor de Z: " << *pz << "\n\n";

    system("pause");
    return 0;
}
