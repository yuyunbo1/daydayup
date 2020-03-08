int winer(char ** board, int boardSize, char one)
{
	int i , j;
	char str[4] = {0};
	for (i = 0; i < boardSize; i++) {
		str[i] = one;
	}

	for (i = 0; i < boardSize; i++) {

		if (strcmp(board[i],str) == 0) {
			return true;
		}
		if (board[0][i] == one && board[1][i] == one && board[2][i] == one) {
			return true;
		}
	}
	if (board[0][0] == one && board[1][1] == one && board[2][2] == one) {
		return true;
	}
	if (board[0][2] == one && board[1][1] == one  && board[2][0] == one) {
		return true;
	} 
	return false;
}


bool validTicTacToe(char ** board, int boardSize){
	int i, j;
	int x_count = 0;
	int o_count = 0;
	for (i = 0; i < boardSize; i++) {
		for (j = 0; j < boardSize; j++) {
			if (board[i][j] == 'X') {
				x_count++;
			}
			else if (board[i][j] == 'O') {
				o_count++;
			}
		}
	}
	// O�����������ܱ�X��������
	if (o_count > x_count) {
		return false;
	}
	// X���������ܱ�O����������2
	if (x_count - o_count >= 2) {
		return false;
	}
    if (x_count - o_count == 1 && winer(board, boardSize, 'O') ) {
        return false;
    }
	// ��2��������ͬ�����ʱ��
	if (x_count == o_count) {
		// ����ͬʱ��Ӯ
        if (winer(board, boardSize, 'X') && winer(board, boardSize, 'O')) {
			printf("1");
            return false;
		}
        // XӮ�˾Ϳ��Խ���
        if (winer(board, boardSize, 'X')) {
            printf("2");
            return false;
        }
	}
	return true;
}