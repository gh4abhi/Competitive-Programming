// Problem Link - https://www.codingninjas.com/codestudio/problems/758961?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

bool isPossible(int matrix[9][9], ll r, ll c, ll val)
{
    for(ll i=0;i<9;i++)
    {
        if(matrix[r][i]==val)
            return false;
        if(matrix[i][c]==val)
            return false;
        if(matrix[3*(r/3) + i/3][3*(c/3) + i%3]==val)
            return false;
    }
    return true;
}

bool DFS(ll matrix[9][9])
{
    for(ll i=0;i<9;i++){
        for(ll j=0;j<9;j++){
            if(matrix[i][j]==0){
                for(ll val=1;val<=9;val++){
                    if(isPossible(matrix,i,j,val)){
                        matrix[i][j] = val;
                        if(DFS(matrix))
                            return true;
                        else
                            matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    return DFS(matrix);
}
