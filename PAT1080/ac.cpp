#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Applicant{
    int id;
    int GE;
    int GI;
    int final_grade;
    int rank;
    int preferred_schools[6];
};

bool cmp(Applicant a,Applicant b){
    if (a.final_grade!=b.final_grade){
        return a.final_grade>b.final_grade;
    } else {
        return a.GE>b.GE;
    }
}

bool cmpById(Applicant a,Applicant b){
    return a.id<b.id;
}

int main(){
    int N,M,K;// 总人数,学校数目，每一个学生的志愿数目
    scanf("%d %d %d",&N,&M,&K);
    int quota[M];// 每一个学校的名额
    for (int i = 0; i < M; ++i) {
        scanf("%d",&quota[i]);
    }
    vector<Applicant> applicants;// 保存所有学生
    Applicant applicant;
    for (int j = 0; j < N; ++j) {
        scanf("%d %d",&applicant.GE,&applicant.GI);
        applicant.final_grade = applicant.GE+applicant.GI;
        applicant.id = j;
        for (int i = 0; i < K; ++i) {
            scanf("%d",&applicant.preferred_schools[i]);
        }
        applicants.push_back(applicant);
    }
    sort(applicants.begin(),applicants.end(),cmp);
    // 获取排名
    for (int k = 0; k < applicants.size(); ++k) {
        if(k==0){
            applicants[k].rank = 1;
        } else if (applicants[k].final_grade==applicants[k-1].final_grade&&applicants[k].GE==applicants[k-1].GE){
            applicants[k].rank = applicants[k-1].rank;
        } else {
            applicants[k].rank = k+1;
        }
    }
    vector<Applicant> schools[M];// 每一个学校录取的学生
    // 处理每一个考生的志愿
    for (int l = 0; l < applicants.size(); ++l) {
        // 遍历所有的志愿
        for (int i = 0; i < K; ++i) {
            int preferred = applicants[l].preferred_schools[i];
            // 首先判断该学校是否招满了
            if(schools[preferred].size()<quota[preferred]||schools[preferred][schools[preferred].size()-1].rank==applicants[l].rank){
                // 没有满，直接招或学校招满了，但是该学生和最后一名排名相同，也招
                schools[preferred].push_back(applicants[l]);
                break;
            } 
        }
    }
    for (int m = 0; m < M; ++m) {
        // 招到学生才进行处理
        if (schools[m].size()>0){
            sort(schools[m].begin(),schools[m].end(),cmpById);
            for (int i = 0; i < schools[m].size(); ++i) {
                printf("%d",schools[m][i].id);
                if (i<schools[m].size()-1) printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}