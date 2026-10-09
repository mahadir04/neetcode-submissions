class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i = 0; 
        while(i < 9) 
        {
            bool temRow[256] = {false}; 
            for(int j = 0; j < 9; j++) 
            {
                char cur = board[i][j];
                if(isdigit(cur))
                {
                    if(temRow[cur] == true) 
                    {
                        return false; 
                    }
                    temRow[cur] = true;
                }
            }

            bool temCol[256] = {false}; 
            for(int k = 0; k < 9; k++) 
            {
                char cur = board[k][i];
                if(isdigit(cur))
                {
                    if(temCol[cur] == true) 
                    {
                        return false;
                    }
                    temCol[cur] = true;
                }
            }
            i++;
        }

        for(int r = 0; r < 9; r += 3) 
        {
            for(int c = 0; c < 9; c += 3) 
            {
                bool temBox[256] = {false}; 
                for(int i = 0; i < 3; i++) 
                {
                    for(int j = 0; j < 3; j++) 
                    {
                        char cur = board[r + i][c + j];
                        if(isdigit(cur)) 
                        {
                            if(temBox[cur] == true) 
                            {
                                return false;
                            }
                            temBox[cur] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};