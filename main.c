#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> //문자열 비교할때 쓴다던데....
#include <unistd.h> //usleep을 쓸때 필요
#include <stdlib.h> //이게 랜덤 함수인가

/*
       <메인 구역> - 사각형 구조?
*************************
*       *       *       *
*   1   *   2   *   3   * <-----관리구역
*       *       *       *
*************************
*       *       *       *
*   1   *   2   *   3   * <-----생산구역
*       *       *       *
*************************
*       *       *       *
*   1   *   2   *   3   * <-----생활구역
*       *       *       *
*************************



<서브구역-미완성>
##############


*/


/* 변수들... 이긴한데 자료형을 어케해야할지 몰라서 이상함 */
int user_select = 0;
char user_name[128];         //유저 이름 받기
char command[128];           //명령어 받기
int user_money = 100;        //유저 머니
int user_def = 0;            //유저 방어력
int user_hp_max = 100;       //유저 최대 hp
int user_hp_now = 100;       //유저 현재 체력
int user_atk = 10;           //유저 공격력
int user_energy = 0;         //에너지 충전 100% + 충전량
int user_level = 0;          //유저 레벨


/* 기본 화면 구성 함수 */

void progress(max, now){
  int per = (now*100)/max/10; 
  for(int i = 0;i < per;i++){
    printf("█");
  }
  for(int i = 0;i < 10-per;i++){
    printf("░");
  }
  
}



void printmu(char text[128]) {  //윗부분 텍스트
  printf("\n┏━━━━━━━━━━━━%s━━━━━━━━━━━━\n", text);
  usleep(80000);
  printf("┣━━━━━━*.·:·.☽✧ ✦ ✧☾.·:·.*━━━━━━━\n");
  usleep(80000);
  printf("┃ \n");
  usleep(80000);
}

void printm(char script[128]) { //중간부분 텍스트
  printf("┃ ");
  printf("%s",script);
  usleep(80000);
  printf("\n");
}

void printmd() {                //아랫부분 텍스트
  printf("┃ \n");
  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
  usleep(150000);
}

void printml(char texts[128]) { //중간 칸 텍스트
  printf("┃ \n");
  usleep(80000);
  printf("┣━━━━━━━━━━━━%s━━━━━━━━━━━━\n", texts);
  usleep(80000);
  printf("┃ \n");
  usleep(80000);
}

void printm1l(char text[128]) { //텍스트가 함줄일때 간편하게 함

  printmu("𝕊𝕥𝕖𝕝𝕃𝕚𝕗𝕖");
  printm(text);
  printmd();
}

void printmll(){
  printml("━━━━━━━━");
}

//^^^^여기까지 텍스트 출력 관련

 
void guide(){//유저가이드 출력
  printmu("━━𝔾𝕦𝕚𝕕𝕖━");
  printm("info 》 게임 내에서의 나의 정보를 표시합니다.");
  printm("help 》 명령어를 확인할 수 있습니다."); 
  printm("map  》 게임 내에서 현재 위치를 출력합니다.");
  printm("exit 》 게임을 종료하고 메인화면으로 이동합니다."); 
  printmd();
}

void startGame() {//게임 시작
  printmu("𝕊𝕥𝕖𝕝𝕃𝕚𝕗𝕖");
  printm("삐-삐-삐");
  printm("??? : \"WAKE\" 상태가 확인됨.");
  printm("가이드 프로그램 가동.");
  printm(".........삐빗");
  printml("━━━━━━━━");

  usleep(500000);
  printm("??? : 반갑습니다.");
  printmd();
  usleep(500000);
  printmu("ℂ𝕠𝕞𝕞𝕒𝕟𝕕");
  printm("1 》누구세요.....?");
  printm("2 》여긴어디....?");
  printmd();

  while (1) {//게임 배경 설명(위치or누군지)
    printf("▶");
    scanf("%d", &user_select);
    usleep(100000);
    if (user_select == 1) {//누군지 + 배경
      printmu("𝕊𝕥𝕖𝕝𝕃𝕚𝕗𝕖");
      printm("저는 스텔라이프 시스템의 가이드 ai입니다.");
      printm("귀하께서는 2030년 첨단 프로젝트");
      printm("\"스텔라이프\"에 참가해 주셨습니다.");
      printmd();
      break;
    } else if (user_select == 2) {//위치 + 배경
      printmu("𝕊𝕥𝕖𝕝𝕃𝕚𝕗𝕖");
      printm("이곳은 \"스텔라이프 행성\"의 메인-관리-2");
      printm("구역이며, 이곳은 가이드 전용 구역입니다.");
      printmd();
      break;
    } else {//잘못된 입력
      user_select = 0;
      printmu("━ℕ𝕠𝕥𝕚𝕔𝕖━");
      printm("잘못된 입력입니다.");
      printm("화면에 표시된 번호를 입력해 주세요.");
      printmd();
    }
  }
  usleep(500000);
  printmu("ℂ𝕠𝕞𝕞𝕒𝕟𝕕━");
  printm("1 》스텔라이프....?");
  printmd();

  while (1) {//배경설명2
    printf("▶");
    scanf("%d", &user_select);
    usleep(100000);
    if (user_select == 1) {//배경설명2
      printmu("𝕊𝕥𝕖𝕝𝕃𝕚𝕗𝕖");
      printm("Guider : \"스텔라이프\"에");
      printm("대한 기억이 없으신가요?");
      printml("━━━━━━━━");
      printm("스텔라이프 프로젝트란 2030년");
      printm("지구 운석 충돌을 대비해");
      printm("인간을 수면냉동 처리하여");
      printm("새로운 행성을 찾아 정착을");
      printm("시도하는 프로젝트 입니다.");
      printmd();
      break;
    } else {//잘못된선택
      user_select = 0;
      printmu("━ℕ𝕠𝕥𝕚𝕔𝕖━");
      printm("잘못된 입력입니다.");
      printm("화면에 표시된 번호를 입력해 주세요.");
      printmd();
    }
  }



  usleep(500000);
  printmu("ℂ𝕠𝕞𝕞𝕒𝕟𝕕━");
  printm("1 》수면 냉동....?");
  printm("2 》새로운 행성?");
  printmd();

  while (1) {//배경설명3
    printf("▶");
    scanf("%d", &user_select);
    usleep(100000);
    if (user_select == 1||user_select == 2) {//뭐라도 쳐야지 넘어가짐
      break;
    } else {//잘못된 입력
        user_select = 0;
      printmu("━ℕ𝕠𝕥𝕚𝕔𝕖━");
      printm("잘못된 입력입니다.");
      printm("화면에 표시된 번호를 입력해 주세요.");
      printmd();
    }
  }



  usleep(500000);
  printmu("𝕊𝕥𝕖𝕝𝕃𝕚𝕗𝕖");//스토리 3
  printm("Guider : 귀하께서는 이 프로젝트의");
  printm("마지막 동면자였습니다.");
  printm("일어나는 순서는");
  printm("한번에 모든 인간이 깨어났을때");
  printm("일어날 혼등을 예측하기 어려워");
  printm("무작위로 해동진행하였습니다.");
  printml("━━━━━━━━");
  printm("이곳에서 살아가려면");//아이디 가입필요!
  printm("\"스텔라 시스템\"에 가입해야합니다.");
  printm("스텔라 시스템에서 사용할 코드네임을");
  printm("입력해 주십시오");
  printmd();
  usleep(500000);
  printmu("ℂ𝕠𝕞𝕞𝕒𝕟𝕕");//아이디 생성
  printm("ID 》아이디를 직접 입력하세요!");
  printmd();
  printf("▶");
  scanf("%s", user_name);//아이디 물어보기
  usleep(100000);
  printmu("𝕊𝕥𝕖𝕝𝕃𝕚𝕗𝕖");
   printm("확인되었습니다.");
  printf("┃ \"");
  printf("%s",user_name);
  printf("\" 코드네임으로 등록되었습니다.\n");
  printmll();
  printm("Guider : 추후 궁금하신점이 있으시면,");
  printm("언제든지 스텔라시스템에서");
  printm("도움을 받을수 있습니다.");
  printm("스텔라 시스템 사용법이 궁금하시다면");
  printm("언제든지 \"help\"를 입력 하세요.");
   printmd();

   usleep(1000000);
printmu("𝕊𝕥𝕖𝕝𝕃𝕚𝕗𝕖");
   printm("아이디 생성 절차 종료. ");
  printm("스텔라이프를 즐겨보세요!");
  printmd();

  user_level=1;//튜토리얼 봤는지에 대한 정보
  maingame();//메인 게임

}

int userInfo(){//내정보
  printmu("𝕊𝕥𝕖𝕝𝕃𝕚𝕗𝕖");
  printf("┃ UserId : ");//유저이름
  printf("%s",user_name);
  printf("\n");
  printm("Location : 아직임");
  printmd();
  return 0;
}



int maingame(){//메인게임
  if(user_level==0){//튜토리얼을 한번 건너뛰었을시 튜토리얼을 본걸로 처리
    user_level=1;
  }
while(1){//명령어사용을 위한 무한 반복
  printf("▶");
  scanf("%s", command);
  usleep(100000);
  if(strcmp(command, "help") == 0||strcmp(command, "도움") == 0||strcmp(command, "가이드") == 0)
  {//가이드&도움 명령어
    guide();
  }
  else if(strcmp(command, "exit") == 0||strcmp(command, "나가기") == 0)
  {//나가기 명령어
  main();
  }
  else if(strcmp(command, "info") == 0||strcmp(command, "정보") == 0)
  {//내 정보 표시
    userInfo();

  }
  else if(strcmp(command, "map") == 0||strcmp(command, "맵") == 0||strcmp(command, "위치") == 0)
  {
    
  }
  else
  {//아무것도 해당되지 않는 명령어 일때

    printm1l("해당 명령어를 찾을수 없습니다.");
  }
}
return 0;
}







int main()  {//메인 (가장먼저 실행)

    while (1)  {//홈 메뉴

        printmu("𝕊𝕥𝕖𝕝𝕃𝕚𝕗𝕖");
        printm("1 》게임 시작");
        printm("2 》게임 가이드");
        printm("3 》게임 종료");
        printmd();
      

        printf("▶");
        scanf("%d", &user_select);//게임메뉴 선택
        usleep(100000);
        if (user_select == 1)  {//게임시작 부분
              user_select = 0;

          if(user_level!=0){//튜토리얼을 봤는가?(봤으면1)
            printm1l("게임을 시작합니다.");

            maingame();
          }else{//안봤으면 실행(0이면)

            printmu("𝕊𝕥𝕖𝕝𝕃𝕚𝕗𝕖");
            printm("튜토리얼을 보시겠습니까?");
            printml("ℂ𝕠𝕞𝕞𝕒𝕟𝕕━");
            printm("1 》튜토리얼 보기");
            printm("2 》튜토리얼 건너뛰기");
            printmd();
            while (1){ //튜토리얼 볼껀지물어보기
            printf("▶");
            scanf("%d", &user_select);

            if(user_select==1){//튜토리얼 본다 했을땨
            printm1l("튜토리얼을 시작합니다.");
            startGame();
            }else if(user_select == 2){//안본다했을때
              printm1l("튜토리얼을 건너뛰고 시작합니다.");
              printmu("ℂ𝕠𝕞𝕞𝕒𝕟𝕕");
              printm("ID 》사용할 아이디를 직접 입력하세요!");
              printmd();
              printf("▶");
              scanf("%s", user_name);//아이디 등록하고 가야함
              usleep(100000);
              printmu("𝕊𝕥𝕖𝕝𝕃𝕚𝕗𝕖");
              printf("┃ 코드네임 \"");
              printf("%s",user_name);
              printf("\" 으로 등록되었습니다.\n");
              printmll(); 
              printm("스텔라 시스템 사용법이 궁금하시다면");
              printm("언제든지 \"help\"를 입력 하세요.");
               printmd();
              char user_location[128] = "메인-관리-2";
              maingame();//메인게임
            }else{//잘못된 선택
                user_select = 0;
              printmu("━ℕ𝕠𝕥𝕚𝕔𝕖━");
              printm("잘못된 입력입니다.");
              printm("화면에 표시된 번호를 입력해 주세요.");
              printmd();
            }

            }
          }
            break;
        } else if (user_select == 2)  {//가이드 메뉴 부분
              user_select = 0;

            while (1) { //가이드메뉴
                  user_select = 0;

                printmu("━━𝔾𝕦𝕚𝕕𝕖━");
                printm("i 》 게임 내에서의 나의 정보를 표시합니다.");
                printml("ℂ𝕠𝕞𝕞𝕒𝕟𝕕━");
                printm("1 》메인 화면으로 돌아가기");
                printmd();
                printf("▶");
                scanf("%d", &user_select);
                usleep(100000);
                if (user_select == 1)  {//메인화면으로 돌아갈지
                    printmu("━ℕ𝕠𝕥𝕚𝕔𝕖━");
                    printm("메인 화면으로 돌아갑니다.");
                    printmd();
                    main();
                    break;
                } else  {//잘못된 입력
                    printmu("━ℕ𝕠𝕥𝕚𝕔𝕖━");
                    printm("잘못된 입력입니다.");
                    printm("화면에 표시된 번호를 입력해 주세요.");
                    printmd();
                };
            }

            break;
        } else if (user_select == 3)  {//게임종료
            system("clear");
            printmu("━ℕ𝕠𝕥𝕚𝕔𝕖━");
            printm("게임을 종료합니다.");
            printmd();
            return 0;
        } else  {//잘못된 입력
              user_select = 0;
            printmu("━ℕ𝕠𝕥𝕚𝕔𝕖━");
            printm("잘못된 입력입니다.");
            printm("화면에 표시된 번호를 입력해 주세요.");
            printmd();
        };
    }

    return 0;
}
