class Solution {
public:
    bool AnswerFound=false;
    void solveSudoku(vector<vector<char>>& board) {
        /*
        Greedy-Searching
        1. Structurlize the squares. 9 Rows, 9 Columns, and 9 Small Squares.
        2. Calculate the "Fullness" for all these 27 structures.
        3. Choose the one with largest fullness as the target
        4. Evaluate all empty cells, calculte the number of cadidates
        5. Choose the one with lowest candidates.
        6. Try every candidate and continue search until Map is full.

        The # of small squares:
            0 1 2
            3 4 5
            6 7 8
        */
        int f_row[9]={0},f_col[9]={0},f_sqr[9]={0};
        set<char>s_row[9],s_col[9],s_sqr[9];
        int maxf_row, maxf_col, maxf_sqr;
        int maxi_row, maxi_col, maxi_sqr;
        int TotalFullness=0;
        int solveI,solveJ;
        if(AnswerFound)
        {
            return;
        }
        //1. Structurlize the board
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    s_row[i].insert(board[i][j]);
                    s_col[j].insert(board[i][j]);
                    s_sqr[int(i/3)*3+int(j/3)].insert(board[i][j]);
                    TotalFullness++;
                }
            }
        if(TotalFullness==81)
        {
            AnswerFound=true;
            return
        }
        //2. Calculate the "Fullness" for all these 27 structures.
        maxf_row=0;
        maxf_col=0;
        maxf_sqr=0;
        for(int i=0;i<9;i++)
        {
            f_row[i]=s_row[i].size();
            if(maxf_row<f_row[i])
            {
                maxf_row=f_row[i];
                maxi_row=i;
            }
            f_col[i]=s_col[i].size();
            if(maxf_col<f_col[i])
            {
                maxf_col=f_col[i];
                maxi_col=i;
            }
            f_sqr[i]=s_sqr[i].size();
            if(maxf_sqr<f_sqr[i])
            {
                maxf_sqr=f_sqr[i];
                maxi_sqr=i;
            }
        }

        //3. Choose the one with largest fullness as the target
        if(maxf_row>maxf_col)//&&maxf_row>maxf_sqr)
        {
            //Choose a row
            int maxf=0,maxj=0;
            for(j=0;j<9;j++)
            {
                if(board[maxi_row][j]=='.')
                {
                    if(maxf<f_col[j])
                    {
                        maxf=f_col[j];
                        maxj=j;
                    }
                }
            }
            solveI=maxi_row;
            solveJ=maxj;
        }
        else //if(maxf_col>maxf_row&&maxf_col>maxf_sqr)
        {
            //Choose a col
            int maxf=0,maxi=0;
            for(i=0;i<9;i++)
            {
                if(board[i][maxi_col]=='.')
                {
                    if(maxf<f_row[i])
                    {
                        maxf=f_row[i];
                        maxi=i;
                    }
                }
            }
            solveI=maxi;
            solveJ=maxi_col;
        }
        /*
        if(maxf_sqr>maxf_col&&maxf_sqr>maxf_col)
        {
            //Choose a squre
        }*/

        //By this time, the square targeted to be solved is [solveI,solveJ]
        //Generate the list of candidates
        set<char> Candidates;
        for(i=0;i<9)


    }
};