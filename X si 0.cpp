#include <iostream>
#include <conio.h>


using namespace std;

char tabla[10] = { 'o','1','2','3','4','5','6','7','8','9' }, model_tabla[10] = { 'o','1','2','3','4','5','6','7','8','9' };
int sc[3], i;

void afisare_tabla()
{

    system("CLS");
    cout << "\n\n\t\tX si O\n\n";
    cout << "    Jucator 1 (X)  -  Jucator 2 (O)" << endl;
    cout << "\tScor:  [" << sc[1] << "] - [" << sc[2] << "]";
    cout << endl << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << tabla[1] << "  |  " << tabla[2] << "  |  " << tabla[3] << endl;
    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << tabla[4] << "  |  " << tabla[5] << "  |  " << tabla[6] << endl;
    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << tabla[7] << "  |  " << tabla[8] << "  |  " << tabla[9] << endl;
    cout << "\t     |     |     " << endl << endl;
}

int status_joc()
{
    if (tabla[1] == tabla[2] && tabla[2] == tabla[3])
        return 1;
    else if (tabla[4] == tabla[5] && tabla[5] == tabla[6])
        return 1;
    else if (tabla[7] == tabla[8] && tabla[8] == tabla[9])
        return 1;
    else if (tabla[1] == tabla[4] && tabla[4] == tabla[7])
        return 1;
    else if (tabla[2] == tabla[5] && tabla[5] == tabla[8])
        return 1;
    else if (tabla[3] == tabla[6] && tabla[6] == tabla[9])
        return 1;
    else if (tabla[1] == tabla[5] && tabla[5] == tabla[9])
        return 1;
    else if (tabla[3] == tabla[5] && tabla[5] == tabla[7])
        return 1;
    else
    {
        for (i = 1; i <= 9; i++)
            if (tabla[i] == i + 48)
                return -1;
        return 0;

    }
}
int main()
{
    system("Color F4");
    int rand, alegere=0, status, a;
joc:
    rand = 0;
    memcpy_s(tabla, 10, model_tabla, 10);
    do
    {
        afisare_tabla();
    alegere_numar:
        cout << "   Jucator " << rand % 2 + 1 << ", alege un numar:";
        while (!_kbhit());
        alegere = _getch()-'0';
        if (tabla[alegere] == alegere + '0')
        {
            if (rand % 2 + 1 == 1)
                tabla[alegere] = 'X';
            else
                tabla[alegere] = 'O';
        }
        else
        {
            afisare_tabla();
            cout << "   Alegerea este invalida!" << endl << endl;
            goto alegere_numar;
        }
        status = status_joc();
        if (status == 1)
        {
            sc[rand % 2 + 1]++;
            afisare_tabla();
            cout << "\tJucatorul " << rand % 2 + 1 << " a castigat! Felicitari!" << endl;
            cout << "\tDoriti sa jucati din nou?" << endl << "\t1 - Da" << endl << "\t2 - Nu" << endl << endl << "   Alegere:";
            while (!_kbhit());
            a = _getch()-'0';
            if (a == 1)
                goto joc;
            else
            {
                cout << endl << "\tMultumesc ca ati ales jocul meu! Sper ca v-ati distrat!" << endl;
                return 0;
            }
        }
        else if (status == 0)
        {
            afisare_tabla();
            cout << "Meciul s-a terminat intr-o egalitate!" << endl;
            cout << "\tDoriti sa jucati din nou?" << endl << "\t1 - Da" << endl << "\t2 - Nu" << endl << endl << "   Alegere:";
            while (!_kbhit());
            a = _getch()-'0';
            if (a == 1)
                goto joc;
            else
            {
                cout << endl << "\tMultumesc ca ati ales jocul meu! Sper ca v-ati distrat!" << endl;
                return 0;
            }
        }
        else
            rand++;
    } while (status == -1);
    return 0;
}
