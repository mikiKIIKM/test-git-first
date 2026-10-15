#include <iostream>
using namespace std;
int MAX_STUDENTS=100;

// 1. 初始化成绩数组（将前n个元素清零）
void initScores(int* scores, int n){
    for (int i=0;i<n;i++){
        scores[i]=0;
    }
}

// 2. 录入成绩
void inputScores(int* scores, int n){
    cout <<"请输入学生成绩"<< endl;
    for (int i=0;i<n;i++){

        cin >> scores[i];
    }
}

// 3. 计算平均分
double calcAverage(const int* scores, int n){
    if (n<=0){return 0;}
    long long ping=0;
    for (int i=0;i<n;i++){
        ping = ping + scores[i];
    }
    double ave=ping*1.0/n;
    return ave;

}

// 4. 安全查询
int safeGet(const int* scores, int n, int index){
    if (index<0 || index>n ){
        cout << "下标越界" << endl;
        return -1;
    }
    return scores[index];
}

// 5. 统计分数段
void countGrades(const int* scores, int n, int* counts){
    for (int i=0;i<5;i++){
        counts[i]=0;
    }
    for (int i=0;i<n;i++){
        if(scores[i]>=90){
            counts[4]++;       
        }else if (scores[i]>= 80) {
            counts[3]++;
        } else if (scores[i]>= 70) {
            counts[2]++; 
        } else if (scores[i]>= 60) {
            counts[1]++;
        } else {
            counts[0]++;
        }
  
    }

}

// 6. 找最高分与最低分
void findMinMax(const int* scores, int n, int* max, int* min){
    if (n <= 0) return;
    *max =scores[0];
    *min =scores[0];
    
    for (int i = 1; i < n; i++) {
        if (scores[i] > *max) {
            *max = scores[i];
        }
        if (scores[i] < *min) {
            *min = scores[i]; 
        }
    }

}

// 7. 打印所有结果
void printResults(const int* scores, int n, double avg, const int* counts, int* max, int* min){

    cout << "成绩列表: ";
    for (int i = 0; i < n; ++i) {
        cout << scores[i] << " ";
    }
    cout << endl;

    cout << "平均分: " << avg << endl;

    cout << "分数段人数:" << endl;
    cout << "0-59: " << counts[0] << endl;
    cout << "60-69: " << counts[1] << endl;
    cout << "70-79: " << counts[2] << endl;
    cout << "80-89: " << counts[3] << endl;
    cout << "90-100: " << counts[4] << endl;

    cout << "最高分: " << *max << endl;
    cout << "最低分: " << *min << endl;
}



int main() {
    int scores[MAX_STUDENTS];
    int n;
    int counts[5] = {0};
    int max = -1, min = -1;
    double avg = 0.0;
    int testIndex;

    // 1. 初始化成绩
    initScores(scores, MAX_STUDENTS);

    // 2. 输入学生人数
    cout << "请输入学生人数: ";
    cin >> n;

    // 3. 调用函数（请确保 0 <= n <= 100）
    inputScores(scores, n);

    avg = calcAverage(scores, n);
    findMinMax(scores, n, &max, &min);
    countGrades(scores, n, counts);

    // 4. 安全查询测试
    cout << "请输入要查询的下标: ";
    cin >> testIndex;

    int queried = safeGet(scores, n, testIndex);
    if (queried != -1) {
        cout << "下标 " << testIndex << " 的成绩是: " << queried << std::endl;
    }
    

    // 5. 打印所有统计结果
    printResults(scores, n, avg, counts, &max, &min);

    return 0;
}
