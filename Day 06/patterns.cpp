#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    /*
    ! Print this pattern:
    * 1 1 1 1
    * 2 2 2 2
    * 3 3 3 3
    * 4 4 4 4
    */

//    for(int i = 1; i <= n; i++) {
//     for(int j = 1; j <= n; j++) {
//         cout << i << " ";
//     }
//     cout << endl;
//    }

       /*
    ! Print this star pattern:
        *
        * *
        * * *
        * * * *
    */

//    for(int i = 0; i < n; i++) {
//     for(int j = 0; j <= i; j++) {
//         cout << "*" << " ";
//     }
//     cout << endl;
//    }

    /*
    ! Print this inverted star pattern:
        * * * *
        * * * 
        * * 
        * 
    */

//    for(int i = 0; i < n; i++) {
//         for(int j = n; j > i; j--) {
//             cout << "*" << " ";
//         }
//         cout << endl;
//    }
   
   
    /*
    ! Print this half pyramid pattern:
        * 1
        * 1 2
        * 1 2 3
        * 1 2 3 4
    */

//    for(int i = 0; i < n; i++) {
//     for(int j = 0; j <= i; j++) {
//         cout << j+1 << " ";
//     }
//     cout << endl;
//    }

    /*
    ! Print this character half pyramid pattern:
        * A
        * B C
        * D E F
        * G H I J
    */

//    char ch = 'A';
//    for(int i = 0; i < n; i++) {
//     for(int j = 0; j <= i; j++) {
//         cout << ch << " ";
//         ch++;
//     }
//     cout << endl;
//    }

    /*
    ! Print this hollow rectangle pattern:
        * * * *
        *     *
        *     *
        * * * *
    */

//    for(int i = 1; i <= n; i++) {
//     for(int j = 1; j <= n; j++) {
//         if(i == 1 || j == 1 || i == n || j == n) {
//             cout << "*" << " ";
//         } else {
//             cout << "  ";
//         }
//     }
//     cout << endl;
//    }


    /*
    ! Print this inverted and rotated half pyramid pattern:
              *
            * *
          * * *
        * * * *
    */

//    for(int i = 0; i < n; i++) {
//     for(int j = 0; j < n - i; j++) {
//         cout << "  ";
//     }
//     for(int k = 0; k <= i; k++) {
//         cout << "* ";
//     }
//     cout << endl;
//    }

    /*
    ! Print this floyd's triangle pattern:
        * 1
        * 2 3
        * 4 5 6
        * 7 8 9 10
        * 11 12 13 14 15
    */
//    int number = 1;
//    for(int i = 0; i < n; i++) {
//     for(int j = 0; j <= i; j++) {
//         cout << number << " ";
//         number++;
//     }
//     cout << endl;
//    }

    /*
    ! Print this diamond pattern:
           *
          * *
         * * *
        * * * *
        * * * *
         * * *
          * *
           *
    */

//    for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n - i; j++) {
//             cout << " ";
//         }
//         for(int k = 0; k <= i; k++) {
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     for(int i = n; i >= 0; i--) {
//         for(int j = 0; j < n - i; j++) {
//             cout << " ";
//         }
//         for(int k = 0; k <= i; k++) {
//             cout << "* ";
//         }
//         cout << endl;
//     }


    /*
    ! Print this butterfly pattern:
        *             *
        * *         * *
        * * *     * * *
        * * * * * * * *
        * * * * * * * *
        * * *     * * *
        * *         * *
        *             *
    */

//    for(int i = 1; i <= n; i++) {
//     for(int j = 1; j <= i; j++) {
//         cout << "* ";
//     }
//     for(int k = 1; k <= n - i; k++) {
//         cout << "  ";
//     }
//     for(int k = 1; k <= n - i; k++) {
//         cout << "  ";
//     }
//     for(int l = 1; l <= i; l++) {
//         cout << "* ";
//     }
//     cout << endl;
//    }
//    for(int i = n; i >= 1; i--) {
//     for(int j = 1; j <= i; j++) {
//         cout << "* ";
//     }
//     for(int k = 1; k <= n - i; k++) {
//         cout << "  ";
//     }
//     for(int k = 1; k <= n - i; k++) {
//         cout << "  ";
//     }
//     for(int l = 1; l <= i; l++) {
//         cout << "* ";
//     }
//     cout << endl;
//    }


    /*
    ! Print this 0-1 triangle pattern:
        * 1
        * 0 1 
        * 1 0 1
        * 0 1 0 1
        * 1 0 1 0 1
    */

//    for(int i = 1; i <= n; i++) {
//     bool num = (i % 2 != 0) ?  true : false;
//     for(int j = 1; j <= i; j++) {
//         cout << num << " ";
//         num = !num;
//     }
//     cout << endl;
//    }

    /*
    ! Print this rhombus pattern:
              * * * *
            * * * *
          * * * *
        * * * *
    */

//    for(int i = 1; i <= n; i++) {
//     for(int j = 1; j <= n - i; j++) {
//         cout << " ";
//     }
//     for(int k = 1; k <= n; k++) {
//         cout << "* ";
//     }
//     cout << endl;
//    }

    /*
    ! Print this palindromic pattern with numbers:
    &                1
    &              2 1 2
    &            3 2 1 2 3
    &          4 3 2 1 2 3 4
    &        5 4 3 2 1 2 3 4 5
    */

   for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n-i; j++) {
        cout << "   ";
    }
    for(int k = i; k >= 1; k--) {
        cout << " " << k << " ";
    }
    for(int l = 2; l <= i; l++) {
        cout << " " << l << " ";
    }
    cout << endl;
   }

    return 0;
}