//函数求数组中的最大值
double MaxOfList(vector<double>x){
    double max=x[0];
    int n=x.size();
    for(int i=0;i<n;i++)
        if(x[i]>max) max=x[i];
    return max;
}

//雅可比迭代公式
void Jacobi(vector<vector<double> > A,vector<double> B,int n){
    vector<double> X(n,0);
    vector<double> Y(n,0);
    vector<double> D(n,0);
    int k=0; //记录循环次数
    do{ 
        X=Y;//注意到这一行代码与高斯赛德尔迭代法的区别
        for(int i=0;i<n;i++){
            double tem=0;
            for(int j=0;j<n;j++){
                if(i!=j) tem += A[i][j]*X[j];
            }
            Y[i]=(B[i]-tem)/A[i][i];
            cout<<left<<setw(8)<<Y[i]<<" ";
        }
        cout<<endl;
        k++;
        if(k>100){
            cout<<"迭代失败！（可能是函数不收敛）"<<endl;
            return ;
        }

        for(int a=0;a<n;a++){
            D[a]=X[a]-Y[a];
        }
    }while( MaxOfList(D)>0.00001 || MaxOfList(D)<-0.00001);

    return ;
}