#include <iostream>

using namespace std;

int main()
{
        int a = 5;
        cout << "input a\n";
        cin >> a;

        int** arr = new int* [a];
        for (int i = 0; i < a; i++)
        {
                arr[i] = new int [a];
        }

        for (int i = 0; i < a; i++)
        {
                for (int j = 0; j < a; j++)
                {
                        asm
                        (
                                "mov %1, %%ebx \n\t"
                                "mov %2, %%eax \n\t"
                                "mov %3, %%edx \n\t"
                                "cmp %%eax, %%edx \n\t"
                                "je 1f \n\t"
                                
                                "add %%edx, %%eax \n\t"
                                "mov %4, %%edx \n\t"
                                "dec %%edx \n\t"
                                "cmp %%eax, %%edx \n\t"
                                "je 1f \n\t"

                                "mov $0, %0 \n\t"
                                "jmp 0f \n\t"

                                "1:  \n\t"
                                        "mov $1, %0 \n\t"
                                "0: \n\t"
                                : "=r" (arr[i][j])
                                : "r" (arr[i][j]), "r" (i), "r" (j), "r" (a)
                                : "eax", "ebx", "edx", "cc"
                        );
                }
        }

        for (int i = 0; i < a; i++)
        {
                for (int j = 0; j < a; j++)
                {
                        cout << arr[i][j]<<"\t";
                }
                cout << endl;
        }
        return 0;
}
