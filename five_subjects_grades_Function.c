#include <stdio.h>
#include <string.h>
struct Grade{
    char id[10];
    int score[5];
}student[30];

float aver_score(struct Grade *subject,int n){
	int i,adder = 0;
	float aver;
	for (i = 0; i < n; i ++){
        adder = adder + (*subject).score[0];
        printf("i:%d,adder:%d\n",i,adder);
        if (i < n-1){
        	subject ++;
		}
    }
    aver = (1.0*adder)/n;
    return aver;
}

void id_fail(struct Grade *mark,int n){
	int i,j,fail = 0,counter = 0,*p_mark;
	char (*p_id)[10];
	p_mark = (*mark).score;
	p_id = (*mark).id;
	for (i = 0; i < n; i ++){
        for (j = 0; j < 5; j ++){
            if (*p_mark < 60){
                fail ++;
            }
            if (j < 4){
                p_mark ++;
			}
        }
        if (fail >= 2){
            printf("%s ",*p_id);
            counter ++;
        }
        fail = 0;
        if (i < n-1){
        	p_mark = &(*(mark+i+1)).score[0];
        	p_id ++;
		}
    }
    if (counter == 0){
        printf("no");
    }
    printf("\n");
}

void id_aver(struct Grade *mark,int n){
	int i,j,sum = 0,counter = 0,*p_mark;
	char (*p_id)[10];
	p_mark = (*mark).score;
	p_id = (*mark).id;
	for (i = 0; i < n; i ++){
        for (j = 0; j < 5; j ++){
            sum = sum + *p_mark;
            printf("%d,%d index:%d\n",i,j,*p_mark);
            if (j < 4){
            	p_mark ++;
			}
        }
        if (sum > 450){
            printf("%s ",*p_id);
            counter ++;
        }
        sum = 0;
        if (i < n-1){
        	p_mark = &(*(mark+i+1)).score[0];
        	p_id ++;
		}
    }
    if (counter == 0){
        printf("no\n");
    }
}

int main(){
    int a,b,n;
    float average;
    scanf("%d",&n);
    for (a = 0; a < n; a ++){
        scanf("%s ",student[a].id);
        for (b = 0; b < 5; b ++){
            if (b < 4){
               scanf("%d ",&student[a].score[b]);
            }else{
               scanf("%d",&student[a].score[b]);
            }
        }
    }
    average = aver_score(student,n); 
    printf("%.2f\n",average);
    id_fail(student,n);
    id_aver(student,n);
    return 0;
}
