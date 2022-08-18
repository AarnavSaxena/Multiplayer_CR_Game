#include<simplecpp>
int abs(int x){
    int i;
    if(x>=0){i=x;}
    else i=-1*x;
    return i;}
bool condition(int p[9][6]){bool i;
    int c1=0;int c2=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<6;j++){
            if(p[i][j]>0){c1++;}
            if(p[i][j]<0){c2++;}
        }
    }
    if((c1==0)or(c2==0)){i = true;}
    else {i=false;}
    return i;
}

void update(int p[9][6],int sign){
    //corners
    int s,cnt=0;
    if(abs(p[0][0])>=2){
         s=abs(p[0][0]);
         s=s-2;
         cnt++;
         p[0][0]=s*sign;
         p[1][0]=sign*(abs(p[1][0])+1);
         p[0][1]=sign*(abs(p[0][1])+1);
    }
    if(condition(p)){
    return;
    }

    if(abs(p[0][5])>=2){
         s=abs(p[0][5]);
         s=s-2;
         cnt++;
         p[0][5]=s*sign;
         p[0][4]=sign*(abs(p[0][4])+1);
         p[1][5]=sign*(abs(p[1][5])+1);
    }
    if(condition(p)){
    return;
    }

    if(abs(p[8][0])>=2){
         s=abs(p[8][0]);
         s=s-2;
         cnt++;
         p[8][0]=s*sign;
         p[7][0]=sign*(abs(p[7][0])+1);
         p[8][1]=sign*(abs(p[8][1])+1);
    }
    if(condition(p)){
    return;
    }

    if(abs(p[8][5])>=2){
         s=abs(p[8][5]);
         s=s-2;
         cnt++;
         p[8][5]=s*sign;
         p[8][4]=sign*(abs(p[8][4])+1);
         p[7][5]=sign*(abs(p[7][5])+1);
    }
    if(condition(p)){
    return;
    }

    // edges
        //lower edge(4)
        for(int j=1;j<5;j++){
            if(abs(p[8][j])>=3){
                s=abs(p[8][j])-3;
                p[8][j]=s*sign;
                cnt++;
                (p[8][j+1])=sign*(abs(p[8][j+1])+1);
                (p[8][j-1])=sign*(abs(p[8][j-1])+1);
                (p[7][j])=sign*(abs(p[7][j])+1);

            }
        }
        if(condition(p)){
    return;
    }
        //upper edge(4)
        for(int j=1;j<5;j++){
            if(abs(p[0][j])>=3){
                s=abs(p[0][j])-3;
                p[0][j]=s*sign;
                cnt++;
                (p[0][j+1])=sign*(abs(p[0][j+1])+1);
                (p[0][j-1])=sign*(abs(p[0][j-1])+1);
                (p[1][j])=sign*(abs(p[1][j])+1);

            }
        }
        if(condition(p)){
    return;
    }
        //left edge(7)
        for(int i=1;i<8;i++){
            if(abs(p[i][0])>=3){
                s=abs(p[i][0])-3;
                p[i][0]=s*sign;
                cnt++;
                (p[i+1][0])=sign*(abs(p[i+1][0])+1);
                (p[i-1][0])=sign*(abs(p[i-1][0])+1);
                (p[i][1])=sign*(abs(p[i][1])+1);

            }
        }
        if(condition(p)){
    return;
    }
        //right edge(7)
        for(int i=1;i<7;i++){
            if(abs(p[i][5])>=3){
                s=abs(p[i][5])-3;
                p[i][5]=s*sign;
                cnt++;
                (p[i+1][5])=sign*(abs(p[i+1][5])+1);
                (p[i-1][5])=sign*(abs(p[i-1][5])+1);
                (p[i][4])=sign*(abs(p[i][4])+1);

            }
        }
        if(condition(p)){
    return;
    }

    //bulk;

    for(int i=1;i<8;i++){
        for(int j=1;j<5;j++){
            if(abs(p[i][j])>=4){
                s=abs(p[i][j])-4;
                p[i][j]=s*sign;
                cnt++;
                p[i][j-1]=sign*(abs(p[i][j-1])+1);
                p[i][j+1]=sign*(abs(p[i][j+1])+1);
                p[i-1][j]=sign*(abs(p[i-1][j])+1);
                p[i+1][j]=sign*(abs(p[i+1][j])+1);

            }
        }
    }
    if(condition(p)){
    return;
    }
    if(cnt!=0){
        update(p,sign);
    }
    else{
        return;
    }
}

main_program{
int x,y,cnt=0,tab[9][6];
for(int i=0;i<9;i++){
    for(int j=0;j<6;j++){
        tab[i][j]=0;
    }

}
while(cin>>x>>y){
    if(x==-1){

        break;
    }
    if((x<0)||(x>8)||(y<0)||(y>5)){
        cout<<"illegal move"<<endl;
        continue;
    }

    int turn=cnt%2;int sign;

    if(turn==0){sign=1;}

    else {sign=-1;};

    if(tab[x][y]!=0){if((tab[x][y]/sign)<0){
    cout<<"illegal move"<<endl;
    continue;}}

    if(cnt%2==0){
        tab[x][y]++;
        cnt++;
        update(tab,sign);

        for(int i=0;i<9;i++){
            for(int j=0;j<6;j++){
                cout<<tab[i][j]<<" ";
            }
            cout<<endl;
        }
        if(cnt>2){
            if(condition(tab)){break;}
            else continue;
        }
        else  continue;
    }

    if(cnt%2==1){
        tab[x][y]--;
        cnt++;
        update(tab,sign);
        for(int i=0;i<9;i++){
            for(int j=0;j<6;j++){
                cout<<tab[i][j]<<" ";
            }
            cout<<endl;
        }
        if(cnt>2){
            if(condition(tab)){break;}
            else continue;
        }
        else continue;

    }
}
}
