class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i = 0; 
        while(i < 9) 
        {
            bool temRow[256] = {false}; 
            for(int j = 0; j < 9; j++) 
            {
                char current = board[i][j];
                if(isdigit(current))
                {
                    if(temRow[current] == true) 
                    {
                        return false; 
                    }
                    temRow[current] = true;
                }
            }

            bool temCol[256] = {false}; 
            for(int k = 0; k < 9; k++) 
            {
                char current = board[k][i];
                if(isdigit(current))
                {
                    if(temCol[current] == true) 
                    {
                        return false;
                    }
                    temCol[current] = true;
                }
            }
            i++;
        }

        for(int rowOffset = 0; rowOffset < 9; rowOffset += 3) 
        {
            for(int colOffset = 0; colOffset < 9; colOffset += 3) 
            {
                bool temBox[256] = {false}; 
                for(int r = 0; r < 3; r++) 
                {
                    for(int c = 0; c < 3; c++) 
                    {
                        char current = board[rowOffset + r][colOffset + c];
                        if(isdigit(current)) 
                        {
                            if(temBox[current] == true) 
                            {
                                return false;
                            }
                            temBox[current] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};