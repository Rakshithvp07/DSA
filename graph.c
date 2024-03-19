#include <stdio.h>
#include <stdbool.h>

#define max 10
int graph[max][max];
bool visited[max];

void matrix(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
}

void dfs(int v ,int n){
    printf("%d ",v);
    visited[v]=true;
    for(int i=0;i<n;i++){
        if(graph[v][i]&& !visited[i]){
            dfs(i,n);
        }
    }
}
int main(){
    int n;
    printf("Enter the N corss matrix: ");
    scanf("%d",&n);
    printf("Enter the Matrix of %dx%d\n",n,n);
    matrix(n);
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int start;
    printf("Enter First Node to be Visited within 0 to %d :",n-1);scanf("%d",&start);
    printf("Depth First Search: ");dfs(start,n);
}
