#include <stdio.h>
#include "dk_tool.h" /*підключення директиви, з яких препроцесор зчитує зміст файлу, що знаходиться в одній папці з виконавчим файлом, а також виконує директиви і підстановки*/
int main(int argc, char *argv[])
{
    int row; //ініціалізація змнних
    int col; //ініціалізація змнних
    int i; //ініціалізація змнних
    int j; //ініціалізація змнних
    static int first_matrix[10][10]; //ініціалізація змнних
    static int second_matrix[20][20]; //ініціалізація змнних

    printf("Dimension of matrix:\n");
    scanf("%i %i", &row, &col); //зчитування значень довжини та висоти рядка так сповпця матриці, введених користувачем з клавіатури

    if (row < 0 || col <= 0) // перевірка введених даних на додатність
    {
        printf("Error. Invalid data input.\n");//виведення повідомлення про помилку у разі від'ємності принаймні одного зі значень
    }


    printf("Elements of first_matrix:\n");
    display_first_matrix(row, col, first_matrix); //виведення на екран уже готової 1 матриці. Код для опитування значеннь матриці розміщений у файлі "dk_tool.h" для кращого зовнішньго вигляду основної програми


    printf("Elements of second_matrix:\n");
    display_second_matrix(row, col, second_matrix); //виведення на екран уже готової 2 матриці. Код для опитування значеннь матриці розміщений у файлі "dk_tool.h" для кращого зовнішньго вигляду основної програми


    printf("Sum of first_matrix and second_matrix:\n");
    sum(row, col, first_matrix, second_matrix); //виведення на екран суми 2 матриць

}
