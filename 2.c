#include<stdio.h>

void depth_search(int row,int n,int adj_matrix[100][100],int traversed[100]){
    int i;
    for(i=0;i<n;i++){
        if(adj_matrix[row][i] == 1 && traversed[i] == 0){
            traversed[i] = 1;
            depth_search(i,n,adj_matrix,traversed);
        }
    }
    return;
}

int main(){
    int n,m,i,j,segments=0;
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

    for(i=0;i<n;i++){
        if(traversed[i]==1) continue;
        else{
            segments++;
            traversed[i]=1;
            depth_search(i,n,adj_matrix,traversed);
        }
    }

    printf("%d\n",segments);
    return 0;
}

//m!das
