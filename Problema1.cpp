#include <iostream>
using namespace std;

const int MAX_LETRAS = 26;
const int MAX_SUMA = 10000; 
const int MAX_LONGITUD = 100;
int M[MAX_LETRAS + 1][MAX_SUMA + 1][MAX_LONGITUD + 1];

int SMH(int i, int s, int l) {
  if (l == 0 && s == 0) return 1;
  if (l == 0 || s < 0 || i > MAX_LETRAS) return 0;
  if (M[i][s][l] != -1) return M[i][s][l];
  M[i][s][l] = SMH(i + 1, s, l) + SMH(i + 1, s - i, l - 1);
  return M[i][s][l];
}

int main() {
  int longitud, suma;
  int case_count = 1;
  while (true) {
    cin >> longitud >> suma;
    if (longitud == 0 && suma == 0) break;
    if (longitud > MAX_LONGITUD || suma > MAX_SUMA) {
      cout << "Case " << case_count << ": 0" << endl;
    } else {
      for (int i = 0; i <= MAX_LETRAS; i++) {
        for (int j = 0; j <= suma; j++) {
          for (int k = 0; k <= longitud; k++)
            M[i][j][k] = -1;
        }
      }
      int resultado = SMH(1, suma, longitud);
      cout << "Case " << case_count << ": " << resultado << endl;
    }
    case_count++;
  }
  return 0;
}
