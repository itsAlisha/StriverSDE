class Solution {
public:
//brute
/*
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                        for(int k=0;k<matrix.size();k++){
                            if(matrix[k][j]!=0) matrix[k][j]=-1;
                        }
                        for(int l=0;l<matrix[0].size();l++){
                            if(matrix[i][l]!=0) matrix[i][l]=-1;
                        }  
            
        }
    }
}
     for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
            }
     }
    }
*/
//better 
/*
void setZeroes(vector<vector<int>>& matrix) {
int n=matrix.size();
int m=matrix[0].size();
vector<int>row(m,0);
vector<int>col(n,0);
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
    if(matrix[i][j]==0){
        row[j]=1;
        col[i]=1;
    }
}
}
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
    if(row[j]==1 || col[i]==1){        
        matrix[i][j]=0;
    }
}
}
}
*/
//optimal

void setZeroes(vector<vector<int>>& matrix) {
    int row0=1;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
        //panga hai 1st row ka which is broken into a row0 and row 1..n-1
                matrix[i][0]=0; //1st col me dikkt nhi make it 0
                if(j!=0){ //for row divide into j=0 and j!=0
                    matrix[0][j]=0;
                }
                    else{
                        row0=0;
                    }
                }
                }
            }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){ //for 1*1 to n-1*m-1
                if(matrix[i][j]!=0){ //reduces calculations
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
                }
            }
        }
        for(int i=0;i<m;i++){ //now 1st row=0
            if(matrix[0][0]==0) matrix[0][i]=0; //make 1st row=0
        }
      for(int i=0;i<n;i++){
            if(row0==0) matrix[i][0]=0; //make 1st col=0
        }
}
};
