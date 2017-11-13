#include<stdio.h>

int depth_search(int row,int n,int adj_matrix[100][100],int traversed[100],int end){
    int i,response;
    for(i=0;i<n;i++){
        if(adj_matrix[row][i] == 1 && traversed[i] == 0){
            traversed[i] = 1;
            if(i == end) return 1;
            else response = depth_search(i,n,adj_matrix,traversed,end);
            if(response == 1) return 1;
        }
    }
    return 0;
}

int main(){
    int n,m,i,j,start,end;
    scanf("%d",&n);
    scanf("%d",&m);
    int adj_matrix[100][100],traversed[100];

    for(i=0;i<n;traversed[i++]=0) for(j=0;j<m;j++) adj_matrix[i][j] = 0;

    for(i=0;i<m;i++){
        /* fill adjacency matrix */
        int a,b;
        scanf("%d %d",&a,&b);
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }

    scanf("%d %d",&start,&end);

    int answer = depth_search(start,n,adj_matrix,traversed,end);

    if(answer == 1) printf("%s\n","Yes");
    else printf("%s\n","No");
    return 0;
}

//m!das
