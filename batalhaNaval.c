#include <stdio.h>

int main() {

    char linhaLetras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int linhaNumeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int tabuleiro[10][10] = {0};

    //Posiciona navio 1 de tamanho 3 na linha 1, colunas 2, 3 e 4

    int navio1_linha = 1;
    int navio1_col_inicio = 2;
    int navio1_tamanho = 3;
    int pode_posicionar1 = 1; // Variável para verificar se o navio pode ser posicionado

    //Verifica sobreposição e se esta nos limites do tabuleiro, e posiciona o navio 1

    if (navio1_linha < 0 || navio1_linha >= 10 || 
        navio1_col_inicio < 0 || (navio1_col_inicio + navio1_tamanho) > 10)
    {
        pode_posicionar1 = 0;
        printf("### ERRO: Navio 1 (Horizontal) está fora dos limites do tabuleiro. ###\n\n");
    }
    
    if (pode_posicionar1 == 1) 
    {
        // Loop de VERIFICAÇÃO de sobreposição
        for (int j = navio1_col_inicio; j < navio1_col_inicio + navio1_tamanho; j++) {
            if (tabuleiro[navio1_linha][j] != 0) {
                pode_posicionar1 = 0;
                printf("### ERRO: Sobreposição detectada para o Navio 1. ###\n\n");
                break;
            }
        }
        // Loop de POSICIONAMENTO do navio
        if (pode_posicionar1 == 1) {
            for (int j = navio1_col_inicio; j < navio1_col_inicio + navio1_tamanho; j++) {
                tabuleiro[navio1_linha][j] = 3;
            }
        }
    }

    //Posiciona navio 2 de tamanho 3 na coluna 7, linhas 4, 5 e 6

    int navio2_col = 7;
    int navio2_linha_inicio = 4;
    int navio2_tamanho = 3;
    int pode_posicionar2 = 1; // Variável para verificar se o navio pode ser posicionado

    if (navio2_col < 0 || navio2_col >= 10 ||
        navio2_linha_inicio < 0 || (navio2_linha_inicio + navio2_tamanho) > 10)
    {
        pode_posicionar2 = 0;
        printf("### ERRO: Navio 2 (Vertical) está fora dos limites do tabuleiro. ###\n\n");
    }

    if (pode_posicionar2 == 1)
    {
        // Loop de VERIFICAÇÃO de sobreposição
        for (int i = navio2_linha_inicio; i < navio2_linha_inicio + navio2_tamanho; i++)
        {
            if (tabuleiro[i][navio2_col] != 0) 
            {
                pode_posicionar2 = 0;
                printf("### ERRO: O Navio 2 (Vertical) sobrepõe o Navio 1. ###\n\n");
                break; 
            }
        }

    if (pode_posicionar2 == 1)
        {
            for (int i = navio2_linha_inicio; i < navio2_linha_inicio + navio2_tamanho; i++)
            {
                tabuleiro[i][navio2_col] = 3;
            }
        }
    }

    /* ----- Navios diagonais ----- */
    int navio3_row_start = 2; 
    int navio3_col_start = 0; 
    int navio3_tamanho = 3;
    int pode_posicionar3 = 1;

    /* Verifica limites para navio diagonal direita */
    if (navio3_row_start < 0 || navio3_row_start + navio3_tamanho > 10 ||
        navio3_col_start < 0 || navio3_col_start + navio3_tamanho > 10) {
        pode_posicionar3 = 0;
        printf("### ERRO: Navio 3 (Diagonal direita) está fora dos limites. ###\n\n");
    }

    /* Verifica sobreposição */
    if (pode_posicionar3 == 1) {
        for (int k = 0; k < navio3_tamanho; k++) {
            int r = navio3_row_start + k;
            int c = navio3_col_start + k;
            if (tabuleiro[r][c] != 0) {
                pode_posicionar3 = 0;
                printf("### ERRO: Navio 3 sobrepõe outro navio. ###\n\n");
                break;
            }
        }
    }

    /* Posiciona navio 3 */
    if (pode_posicionar3 == 1) {
        for (int k = 0; k < navio3_tamanho; k++) {
            int r = navio3_row_start + k;
            int c = navio3_col_start + k;
            tabuleiro[r][c] = 3;
        }
    }

    int navio4_row_start = 2; 
    int navio4_col_start = 8; 
    int navio4_tamanho = 3;
    int pode_posicionar4 = 1;

    /* Verifica limites para navio diagonal esquerda */
    if (navio4_row_start < 0 || navio4_row_start + navio4_tamanho > 10 ||
        navio4_col_start < 0 || navio4_col_start - (navio4_tamanho - 1) < 0) {
        pode_posicionar4 = 0;
        printf("### ERRO: Navio 4 (Diagonal esquerda) está fora dos limites. ###\n\n");
    }

    /* Verifica sobreposição para navio 4 */
    if (pode_posicionar4 == 1) {
        for (int k = 0; k < navio4_tamanho; k++) {
            int r = navio4_row_start + k;
            int c = navio4_col_start - k;
            if (tabuleiro[r][c] != 0) {
                pode_posicionar4 = 0;
                printf("### ERRO: Navio 4 sobrepõe outro navio. ###\n\n");
                break;
            }
        }
    }

    /* Posiciona navio 4 */
    if (pode_posicionar4 == 1) {
        for (int k = 0; k < navio4_tamanho; k++) {
            int r = navio4_row_start + k;
            int c = navio4_col_start - k;
            tabuleiro[r][c] = 3;
        }
    }

    /* ----- Matrizes de habilidade (5x5) ----- */
    /* Todas são construídas dinamicamente usando loops aninhados e condicionais. */
    const int SKILL_SIZE = 5;
    int cone[SKILL_SIZE][SKILL_SIZE];
    int cruz[SKILL_SIZE][SKILL_SIZE];
    int octaedro[SKILL_SIZE][SKILL_SIZE];

    for (int r = 0; r < SKILL_SIZE; r++) {
        for (int c = 0; c < SKILL_SIZE; c++) {
            cone[r][c] = 0;
            cruz[r][c] = 0;
            octaedro[r][c] = 0;
        }
    }

    int center = SKILL_SIZE / 2; 

    for (int r = 0; r < SKILL_SIZE; r++) {
        int radius = r; /* quanto mais baixo, mais largo */
        int cmin = center - radius;
        int cmax = center + radius;
        if (cmin < 0) cmin = 0;
        if (cmax >= SKILL_SIZE) cmax = SKILL_SIZE - 1;
        for (int c = cmin; c <= cmax; c++) {
            cone[r][c] = 1;
        }
    }

    /* Construir Cruz (origem no centro): linha central e coluna central marcadas */
    for (int i = 0; i < SKILL_SIZE; i++) {
        cruz[center][i] = 1;
        cruz[i][center] = 1; 

    /* Construir Octaedro (vista frontal = losango). Usamos a condição |dr|+|dc| <= 1
       para formar o pequeno losango. */
    for (int r = 0; r < SKILL_SIZE; r++) {
        for (int c = 0; c < SKILL_SIZE; c++) {
            int dr = (r - center) >= 0 ? (r - center) : (center - r);
            int dc = (c - center) >= 0 ? (c - center) : (center - c);
            if (dr + dc <= 1) {
                octaedro[r][c] = 1;
            }
        }
    }

    /* ----- Pontos de origem no tabuleiro (definidos aqui diretamente) ----- */
    
    int cone_origin_row = 0 + 0; 
    int cone_origin_col = 5;     

    
    int cruz_origin_row = 6; 
    int cruz_origin_col = 2; 

    int oct_origin_row = 3; 
    int oct_origin_col = 6; 

    /* Sobrepor Cone */
    for (int sr = 0; sr < SKILL_SIZE; sr++) {
        for (int sc = 0; sc < SKILL_SIZE; sc++) {
            if (cone[sr][sc] == 1) {
                int board_r = cone_origin_row + (sr - 0); 
                int board_c = cone_origin_col + (sc - center);
                if (board_r >= 0 && board_r < 10 && board_c >= 0 && board_c < 10) {
                    if (tabuleiro[board_r][board_c] == 0) tabuleiro[board_r][board_c] = 5;
                    else if (tabuleiro[board_r][board_c] == 3) tabuleiro[board_r][board_c] = 8;
                }
            }
        }
    }

    /* Sobrepor Cruz */
    for (int sr = 0; sr < SKILL_SIZE; sr++) {
        for (int sc = 0; sc < SKILL_SIZE; sc++) {
            if (cruz[sr][sc] == 1) {
                int board_r = cruz_origin_row + (sr - center);
                int board_c = cruz_origin_col + (sc - center);
                if (board_r >= 0 && board_r < 10 && board_c >= 0 && board_c < 10) {
                    if (tabuleiro[board_r][board_c] == 0) tabuleiro[board_r][board_c] = 5;
                    else if (tabuleiro[board_r][board_c] == 3) tabuleiro[board_r][board_c] = 8;
                }
            }
        }
    }

    /* Sobrepor Octaedro */
    for (int sr = 0; sr < SKILL_SIZE; sr++) {
        for (int sc = 0; sc < SKILL_SIZE; sc++) {
            if (octaedro[sr][sc] == 1) {
                int board_r = oct_origin_row + (sr - center);
                int board_c = oct_origin_col + (sc - center);
                if (board_r >= 0 && board_r < 10 && board_c >= 0 && board_c < 10) {
                    if (tabuleiro[board_r][board_c] == 0) tabuleiro[board_r][board_c] = 5;
                    else if (tabuleiro[board_r][board_c] == 3) tabuleiro[board_r][board_c] = 8;
                }
            }
        }
    }

    printf("### TABULEIRO BATALHA NAVAL ###\n");

    /* Imprime cabeçalho com as letras das colunas */
    printf("   "); /* espaço para alinhar com os números à esquerda */
    for (int j = 0; j < 10; j++)
    {
        printf("%c ", linhaLetras[j]);
    }
    printf("\n");

    /* Imprime cada linha: primeiro o número (vertical), depois os valores da linha */
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", linhaNumeros[i]);
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }



    return 0;
}