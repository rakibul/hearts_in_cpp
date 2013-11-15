/**
 *
 * @name Hearts Game
 * @author Mohammad Rakibul Haider
 * @version 0.001
 * @since version 0.001
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define Players_Card_Amount 13
#define cards_packet_size 52


//first
string first_card_group;
//first
//winner of the suit
int winner;
//winner of the suit

//card suit
vector <string> suit;
//card suit
//
map <string, int> card_point;
//

//
int local_round;
int global_round;
//

//
map <string, int> given_cards;
//

//Map variable declaration of four player
map <string, int> first_player_cards_map;
map <string, int> second_player_cards_map;
map <string, int> third_player_cards_map;
map <string, int> fourth_player_cards_map;
//Map variable declaration of four player

//Start of four players point variable
int first_player_points;
int second_player_points;
int third_player_points;
int fourth_player_points;
//End of four players point variable


void initialize_plyers_point(){
    first_player_points = second_player_points = third_player_points = fourth_player_points = 0;
}

//Start of Printing player points function
void printing_points(){
    printf("%10s %10s %10s %10s\n", "First", "Second", "Third", "Fourth");
    printf("%10d %10d %10d %10d\n", first_player_points, second_player_points, third_player_points, fourth_player_points);
}
//End of Printing player points function

//Start of all 52 cards container
string cards[cards_packet_size] = {
    "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "CJ", "CQ", "CK", "CA",
    "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "DJ", "DQ", "DK", "DA",
    "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "SJ", "SQ", "SK", "SA",
    "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "HJ", "HQ", "HK", "HA"
};
//End of all 52 cards conainer

//Start of Four player card container
string first_player[Players_Card_Amount];
string second_player[Players_Card_Amount];
string third_player[Players_Card_Amount];
string fourth_player[Players_Card_Amount];
//End of Four player card container


//Start of Four player receving cards container
vector <string> first_player_receiving_cards;
vector <string> second_player_receiving_cards;
vector <string> third_player_receiving_cards;
vector <string> fourth_player_receiving_cards;
//End of Four player receving cards container


//Start of Mapping cards points
void cards_point_mapping(){
    card_point["2"]     = 2;
    card_point["3"]     = 3;
    card_point["4"]     = 4;
    card_point["5"]     = 5;
    card_point["6"]     = 6;
    card_point["7"]     = 7;
    card_point["8"]     = 8;
    card_point["9"]     = 9;
    card_point["10"]    = 10;
    card_point["J"]     = 11;
    card_point["Q"]     = 12;
    card_point["K"]     = 13;
    card_point["A"]     = 14;
}
//End of Mapping cards points

//start of 52 card suffle function
void card_suffle(){
    srand( time(NULL) );

    for(int i=0; i<cards_packet_size; i++){
        int x = rand() % cards_packet_size; //suffle cards
        swap(cards[i], cards[x]); //swaping cards
    }
}
//End of 52 card suffle function


//Start of cards after suffle
void print_cards_after_suffle(){
    puts("Cards After Suffle");
    for(int i=0; i<cards_packet_size; i++){
       cout<<cards[i]<<" ";
    }
    puts("");
}
//End of cards after suffle

//starts of cards dealing
void cards_dealing(){
    int flag, k1, k2, k3, k4;
    k1 = k2 = k3 = k4 = 0;

    for(int i=0; i<cards_packet_size; i++){
        flag = (i+1) % 4;
        switch(flag){
            case 1:
                first_player[k1++]   = cards[i];
                break;
            case 2:
                second_player[k2++]  = cards[i];
                break;
            case 3:
                third_player[k3++]   = cards[i];
                break;
            case 0:
                fourth_player[k4++]  = cards[i];
                break;
        }
    }
}
//End of cards Dealing

void check_four_player_cards(){
    printf("1st Player Cards:");
    for(int i=0; i<Players_Card_Amount; i++)
        if(first_player_cards_map[first_player[i]] == 0)
            printf(" %3s", first_player[i].c_str());
    puts("");

    printf("2nd Player Cards:");
    for(int i=0; i<Players_Card_Amount; i++)
        if(second_player_cards_map[second_player[i]] == 0)
            printf(" %3s", second_player[i].c_str());

    puts("");

    printf("3rd Player Cards:");
    for(int i=0; i<Players_Card_Amount; i++)
        if(third_player_cards_map[third_player[i]] == 0)
            printf(" %3s", third_player[i].c_str());
    puts("");

    printf("4th Player Cards:");
    for(int i=0; i<Players_Card_Amount; i++)
        if(fourth_player_cards_map[fourth_player[i]] == 0)
            printf(" %3s", fourth_player[i].c_str());
    puts("");
}

int check_four_player_cards_for_C2(){
    int flag = 1;
    for(int i=0; i<Players_Card_Amount; i++)
        if(first_player[i] == "C2")
            return flag;
    flag++;

    for(int i=0; i<Players_Card_Amount; i++)
        if(second_player[i] == "C2")
            return flag;
    flag++;

    for(int i=0; i<Players_Card_Amount; i++)
        if(third_player[i] == "C2")
            return flag;
    flag++;

    for(int i=0; i<Players_Card_Amount; i++)
        if(fourth_player[i] == "C2")
            return flag;
}



void printing_first_player_cards(){
    puts("Your cards are:");
    for(int i=0; i<Players_Card_Amount; i++)
        if(first_player_cards_map[first_player[i]] == 0)
            cout<<first_player[i]<<" ";
    puts("");
}

void randomly_select_cards(int player, string cards){
    int flag;
    switch(player){
        case 1:
            flag = 0;
            for(int i=0; i<Players_Card_Amount; i++){
                if(first_player_cards_map[first_player[i]] == 0) {
                    if(first_player[i][0] == cards[0]){
                        given_cards[first_player[i]] = 1;
                        first_player_cards_map[first_player[i]] = 1;
                        printf("1st Player: %3s\n", first_player[i].c_str());
                        suit.push_back(first_player[i]);
                        flag = 1;
                        break;
                    }
                }
            }

            if(flag == 0){
                for(int i=0; i<Players_Card_Amount; i++){
                    if(first_player_cards_map[first_player[i]] == 0) {
                        given_cards[first_player[i]] = 1;
                        first_player_cards_map[first_player[i]] = 1;
                        printf("1st Player: %3s\n", first_player[i].c_str());
                        suit.push_back(first_player[i]);
                        break;
                    }
                }
            }

            break;
        case 2:
            flag = 0;
            for(int i=0; i<Players_Card_Amount; i++){
                if(second_player_cards_map[second_player[i]] == 0) {
                    if(second_player[i][0] == cards[0]){
                        given_cards[second_player[i]] = 2;
                        second_player_cards_map[second_player[i]] = 1;
                        printf("2nd Player: %3s\n", second_player[i].c_str());
                        suit.push_back(second_player[i]);
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 0){
                for(int i=0; i<Players_Card_Amount; i++){
                    if(second_player_cards_map[second_player[i]] == 0) {
                        given_cards[second_player[i]] = 2;
                        second_player_cards_map[second_player[i]] = 1;
                        printf("2nd Player: %3s\n", second_player[i].c_str());
                        suit.push_back(second_player[i]);
                        flag = 1;
                        break;
                    }
                }
            }
            break;
        case 3:
            flag = 0;
            for(int i=0; i<Players_Card_Amount; i++){
                if(third_player_cards_map[third_player[i]] == 0) {
                    if(third_player[i][0] == cards[0]){
                        given_cards[third_player[i]] = 3;
                        third_player_cards_map[third_player[i]] = 1;
                        printf("3rd Player: %3s\n", third_player[i].c_str());
                        suit.push_back(third_player[i]);
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 0){
                for(int i=0; i<Players_Card_Amount; i++){
                    if(third_player_cards_map[third_player[i]] == 0) {
                        given_cards[third_player[i]] = 3;
                        third_player_cards_map[third_player[i]] = 1;
                        printf("3rd Player: %3s\n", third_player[i].c_str());
                        suit.push_back(third_player[i]);
                        break;
                    }
                }
            }
            break;
        case 0:
            flag = 0;
            for(int i=0; i<Players_Card_Amount; i++){
                if(fourth_player_cards_map[fourth_player[i]] == 0) {
                    if(fourth_player[i][0] == cards[0]){
                        given_cards[fourth_player[i]] = 4;
                        fourth_player_cards_map[fourth_player[i]] = 1;
                        printf("4th Player: %3s\n", fourth_player[i].c_str());
                        suit.push_back(fourth_player[i]);
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 0){
                for(int i=0; i<Players_Card_Amount; i++){
                    if(fourth_player_cards_map[fourth_player[i]] == 0) {
                        given_cards[fourth_player[i]] = 4;
                        fourth_player_cards_map[fourth_player[i]] = 1;
                        printf("4th Player: %3s\n", fourth_player[i].c_str());
                        suit.push_back(fourth_player[i]);
                        break;
                    }
                }
            }
            break;
    }
}

void randomly_select_first_cards(int player){
    switch(player){
        case 1:
            for(int i=0; i<Players_Card_Amount; i++){
                if(first_player_cards_map[first_player[i]] == 0) {
                    given_cards[first_player[i]] = 1;
                    first_player_cards_map[first_player[i]] = 1;
                    printf("1st Player: %3s\n",first_player[i].c_str());
                    suit.push_back(first_player[i]);
                    first_card_group = first_player[i][0];
                    break;
                }
            }
            break;
        case 2:
            for(int i=0; i<Players_Card_Amount; i++){
                if(second_player_cards_map[second_player[i]] == 0) {
                    given_cards[second_player[i]] = 2;
                    second_player_cards_map[second_player[i]] = 1;
                    printf("2nd Player: %3s\n",second_player[i].c_str());
                    suit.push_back(second_player[i]);
                    first_card_group = second_player[i][0];
                    break;
                }
            }
            break;
        case 3:
            for(int i=0; i<Players_Card_Amount; i++){
                if(third_player_cards_map[third_player[i]] == 0) {
                    given_cards[third_player[i]] = 3;
                    third_player_cards_map[third_player[i]] = 1;
                    printf("3rd Player: %3s\n", third_player[i].c_str());
                    suit.push_back(third_player[i]);
                    first_card_group = third_player[i][0];
                    break;
                }
            }
            break;
        case 0:
            for(int i=0; i<Players_Card_Amount; i++){
                if(fourth_player_cards_map[fourth_player[i]] == 0) {
                    given_cards[fourth_player[i]] = 4;
                    fourth_player_cards_map[fourth_player[i]] = 1;
                    printf("4th Player: %3s\n", fourth_player[i].c_str());
                    suit.push_back(fourth_player[i]);
                    first_card_group = fourth_player[i][0];
                    break;
                }
            }
            break;
    }
}

void print_star(){
    for(int i=0; i<55; i++)
        printf("*");
    puts("");
}

void find_best_card(string card){

    int mx = 0;
    string best_card = "";
    for(int i=0; i<suit.size(); i++){
        if(suit[i][0] == card[0]){
            string bs = "";
            for(int j=1; j<suit[i].size(); j++)
                bs += suit[i][j];
            if(card_point[bs] > mx){
                mx = card_point[bs];
                best_card = suit[i];
            }
        }
    }
    winner = given_cards[best_card];
    print_star();
    switch(winner){
        case 1:
            printf("Suit winner First Player and cards are");
            for(int i=0; i<suit.size(); i++){
                cout<<" "<<suit[i];
                first_player_receiving_cards.push_back(suit[i]);
            }

        break;
        case 2:
            printf("Suit winner Second Player and cards are");
            for(int i=0; i<suit.size(); i++){
                cout<<" "<<suit[i];
                second_player_receiving_cards.push_back(suit[i]);
            }
        break;
        case 3:
            printf("Suit winner Third Player and cards are");
            for(int i=0; i<suit.size(); i++){
                cout<<" "<<suit[i];
                third_player_receiving_cards.push_back(suit[i]);
            }
        break;
        case 4:
            printf("Suit winner Fourth Player and cards are");
            for(int i=0; i<suit.size(); i++){
                cout<<" "<<suit[i];
                fourth_player_receiving_cards.push_back(suit[i]);
            }
        break;
    }
    puts("");
    print_star();
    given_cards.clear();
    suit.clear();
}

void print_lines(int len){
    for(int i=0; i<len; i++)
        printf("-");
    puts("");
}

void print_each_player_points(){
    int total_cards = 0;

    string cards = "";
    for(int i=0; i<first_player_receiving_cards.size(); i++){
        if(first_player_receiving_cards[i][0]=='H')
            first_player_points++;
        if(first_player_receiving_cards[i] == "SQ")
            first_player_points += 13;
        cards += first_player_receiving_cards[i];
        cards += " ";
    }
    cout<<"1st: "<<cards<<endl;
    cards.clear();

    for(int i=0; i<second_player_receiving_cards.size(); i++){
        if(second_player_receiving_cards[i][0]=='H')
            second_player_points++;
        if(second_player_receiving_cards[i] == "SQ")
            second_player_points += 13;
        cout<<second_player_receiving_cards[i]<<" ";
        cards += second_player_receiving_cards[i];
        cards += " ";
    }
    cout<<"2nd: "<<cards<<endl;
    cards.clear();

    for(int i=0; i<third_player_receiving_cards.size(); i++){
        if(third_player_receiving_cards[i][0]=='H')
            third_player_points++;
        if(third_player_receiving_cards[i] == "SQ")
            third_player_points += 13;
        cards += third_player_receiving_cards[i];
        cards += " ";
    }
    cout<<"3rd: "<<cards<<endl;
    cards.clear();

    for(int i=0; i<fourth_player_receiving_cards.size(); i++){
        if(fourth_player_receiving_cards[i][0]=='H')
            fourth_player_points++;
        if(fourth_player_receiving_cards[i] == "SQ")
            fourth_player_points += 13;
        cards += fourth_player_receiving_cards[i];
        cards += " ";
    }
    cout<<"4th: "<<cards<<endl;
    cards.clear();

    print_lines(30);
    printf("%6s %5s %11s\n", "Player", "Point", "Total Cards");
    print_lines(30);
    printf("%6s %5d %6d\n", "First", first_player_points, first_player_receiving_cards.size());
    printf("%6s %5d %6d\n", "Second", second_player_points, second_player_receiving_cards.size());
    printf("%6s %5d %6d\n", "Third", third_player_points, third_player_receiving_cards.size());
    printf("%6s %5d %6d\n", "Fourth", fourth_player_points, fourth_player_receiving_cards.size());
    print_lines(30);

    cout<<"Total cards "<<
          first_player_receiving_cards.size()
        + second_player_receiving_cards.size()
        + third_player_receiving_cards.size()
        + fourth_player_receiving_cards.size()
        <<endl;

    cout<<"Total Points "<<
          first_player_points
        + second_player_points
        + third_player_points
        + fourth_player_points
        <<endl;

    first_player_receiving_cards.clear();
    second_player_receiving_cards.clear();
    third_player_receiving_cards.clear();
    fourth_player_receiving_cards.clear();

    first_player_cards_map.clear();
    second_player_cards_map.clear();
    third_player_cards_map.clear();
    fourth_player_cards_map.clear();
}

int main()
{

    //freopen("output.txt", "w", stdout);
    initialize_plyers_point();
    cards_point_mapping();
    //break point
    local_round = 1;
    card_suffle(); //suffle all 52 cards
    cards_dealing();
    print_cards_after_suffle();

    for(int i=0; i<=13; i++){
        printf("\nTurn %d\n", local_round);
        check_four_player_cards();
        if(i == 0){
            int first_card = check_four_player_cards_for_C2();
            suit.push_back("C2");
            switch(first_card){
                case 1:
                    given_cards["C2"] = 1;
                    first_player_cards_map["C2"] = 1;
                    printf("1st Player: %3s\n", "C2");
                    break;
                case 2:
                    given_cards["C2"] = 2;
                    second_player_cards_map["C2"] = 1;
                    printf("2nd Player: %3s\n", "C2");
                    break;
                case 3:
                    given_cards["C2"] = 3;
                    third_player_cards_map["C2"] = 1;
                    printf("3rd Player: %3s\n", "C2");
                    break;
                case 4:
                    given_cards["C2"] = 4;
                    fourth_player_cards_map["C2"] = 1;
                    printf("4th Player: %3s\n", "C2");
                    break;
            }

            int cnt = 0;
            for(int i=first_card+1; ;i++){
                if(cnt == 3) break;
                randomly_select_cards((i%4), "C");
                cnt++;
            }
            find_best_card("C");
        } else{
            randomly_select_first_cards(winner%4);
            int cnt = 0;
            for(int i=winner+1; ;i++){
                if(cnt == 3) break;
                randomly_select_cards((i%4), first_card_group);
                cnt++;
            }
            find_best_card(first_card_group);
        }

        local_round++;
        if(local_round > 13)
            break;
    }
    puts("");
    puts("Round Result");
    print_each_player_points();
    return 0;
}
