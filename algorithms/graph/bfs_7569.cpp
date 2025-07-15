/*

입력
테스트케이스 수
항목 - 최대칼로리

점수 - 칼로리 
...
...
점수 - 칼로리

가장 높은 점수중 칼로리... 선택

-------

전형적인 dp문제....

dp unordered_map  생성
칼로리 -점수로

아이템 벡터에서 각 아이템당
현재 dp에 담겨져있는 값이랑 비교해서 담기





*/

/*

#include <iostream>
#include <vector>
#include <unordered_map>



typedef struct iteam{
  int cal;
  int score;
}iteam;

int main(){
int TEST_CASE;
std::cin>>TEST_CASE;
for(int T = 1; T<=TEST_CASE; T++){

int iteam_num;
std::vector<iteam> iteam_vector;

std::cin>>iteam_num;
int max_cal;
std::cin >> max_cal;

for(int i= 0 ; i<iteam_num; i++){ //입력받기
  iteam input;
    //입력 : 점수 - 칼로리
  std::cin >> input.score;
  std::cin >> input.cal;

  //unordered_map first = cal , secound = score;
  iteam_vector.push_back(input);
}


std::unordered_map<int,int> dp; //first = cla, secound = score;
dp.insert({0,0});

 //dp계산

  
  
for(auto j : iteam_vector){ //dp
  std::unordered_map<int,int> prev_dp = dp;
  
  for(auto k: prev_dp){
    int cur_cal = k.first + j.cal;
    int cur_score = k.second + j.score;
    
    if(cur_cal<=max_cal){

      auto prev_val = prev_dp.find(cur_cal);

      if( prev_val != prev_dp.end() ){
        if(cur_score>prev_val->second){
          dp[cur_cal]=cur_score;
        }
      }
      else{
        dp.insert({cur_cal,cur_score});
      }


    }
    else{
      
    }

  }

}


int max = 0;

for(auto i : dp){
  if(i.second >max){
    max = i.second;
  }
}
std::cout <<"#"<< T<<" "<< max<<std::endl;

}

}

*/
/*
#include <iostream>


int main(){
int TEST_CASE;
std::cin>> TEST_CASE;
  for(int t = 1; t <= TEST_CASE; t++){
    int iteam;
    
    std::cin >> iteam;
    int max_cal;
    std:: cin >> max_cal;
    int* dp = new int[max_cal]();
    
    for(int i = 0; i<iteam; i++){
      int input_score;
      int input_cal;
      std::cin>>input_score;
      std::cin>>input_cal;

      for(int j = max_cal; j>=input_cal; j--){
        if(  dp[j] < dp[j-input_cal ] + input_score  ){
          dp[j] = dp[j-input_cal ] + input_score;
        }
      }

    }

    std::cout<< "#" << t << " " << dp[max_cal]<<std::endl;
  }

}
*/
