#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>


class player {
	public:
		void update_bat_runs(int scored){runs_bat = runs_bat + scored;}

		void update_bow_runs(int scored){runs_bow = runs_bow + scored;}

		void update_wickets (){wickets++;}

		void update_over_bowled(){overs++;}

		void update_out (int way_out, int bowl, int fiel){how_out = way_out;
			bowler = bowl; fielder = fiel;}

			void fix_stat(int bat, int bow, int field){bat_stat = bat; bow_stat = bow;
				field_stat = field;}

				void name_of_player(char* ptr_to_name){strcpy (name, ptr_to_name);}

				int bat_stat, bow_stat, field_stat, runs_bat, runs_bow, wickets, overs;
				int how_out, bowler, fielder;
				char name[20];
};
typedef player* PLAYERPTRCLASS;

class scoreboard {
	public:
		int runs, wickets, overs;

	public:
		void update_runs (int scored){runs = runs + scored;}

		void update_wick (){wickets++;}

		void update_overs (){overs++;}
};

struct team {
	player indi[12];
	char team_name[20];
};
typedef struct team TEAM;

void out_to_screen (TEAM team[], scoreboard board[], int win);
void generate_team(TEAM *team);
int simulate_match(TEAM team[], scoreboard board[]);



int main()
{
	TEAM team[3];
	scoreboard board[3];
	int w, x, c;
	c = 1;
	generate_team(team);
	while (c == 1)
	{
		/* Initialize data */
		for (w = 0; w < 3; w++)
		{
			board[w].runs = 0;
			board[w].wickets = 0;
			board[w].overs = 0;
		}

		for (w = 0; w < 12; w++)
		{
			for (x = 0; x < 3; x++)
			{
				team[x].indi[w].runs_bat = 0;
				team[x].indi[w].runs_bow = 0;
				team[x].indi[w].wickets = 0;
				team[x].indi[w].overs = 0;
				team[x].indi[w].how_out = 0;
				team[x].indi[w].fielder = 0;
				team[x].indi[w].bowler = 0;
			}
		}

		int win=0;
		win = simulate_match(team, board);
		out_to_screen (team, board, win) ;
		cout << "Do you wish to play another game?\n If yes press 1, else anything.\n =>";
		cin >> c;
		if (c != 1)
		{
			cout << "Exiting Now...\n";
			return 0;
		}
	}

	return 0;
}

/* Output the results */
void out_to_screen (TEAM team[], scoreboard board[], int win)
{
	int f,i;
	for (f= 1; f < 3; f++)
	{
		int batting, bowling;
		if (f == 1)
		{
			batting = 1;
			bowling = 2;
		}
		else
		{
			batting = 2;
			bowling = 1;
		}
		cout << "\n\n";
		cout << "====================================";
		cout << "\n";
		cout << "\t" << team[batting].team_name << endl;
		cout << "====================================";
		cout << "\n";
		for (i=1; i < 12; i++)
		{
			cout << team[batting].indi[i].name;
			int length=0;
			while (team[batting].indi[i].name[length] != '\0')
				length++;
			length = 20 - length;
			while (length != 0)
			{ 
				cout << " ";
				length--;
			}
			int tmp;
			tmp = team[batting].indi[i].fielder;
			if (tmp > 0)
			{
				cout << "Caught\t";
				cout << team[bowling].indi[tmp].name << "\t";
			}
			else if ( team[batting].indi[i].bowler > 1 )
			{
				cout << "Bowled\t\t\t";
			}

			else
			{
				cout << "Not out\t\t\t\t";
			}
			cout << team[bowling].indi[team[batting].indi[i].bowler].name ;
			cout << "\t" << team[batting].indi[i].runs_bat << endl;
		}
		cout << board[batting].runs << "/" << board[batting].wickets 
			<< " in " << board[batting].overs << " overs\n";
		cout << "\n";
		cout << "Player Name         \tOvers\tRuns\tWickets\n";
		for (i=11; i > 5; i--)
		{
			cout << team[bowling].indi[i].name;
			int length=0;
			while (team[bowling].indi[i].name[length] != '\0')
				length++;
			length = 20 - length;
			while (length != 0)
			{ 
				cout << " ";
				length--;
			}
			cout <<  "\t" << team[bowling].indi[i].overs << "\t" << team[bowling].indi[i].runs_bow
				<< "\t" << team[bowling].indi[i].wickets << endl;
		}
		/*	cout << "Ready to proceed? Press Y & Enter to go on.\n>> ";
			char letter;
			cin >> letter;
			while ((letter != 'y') && (letter != 'Y'))
			{
			cout << ">>";
			cin >> letter;
			}*/ }
		cout << "Congratualations ";
		if (win == 1)
		{
			cout << team[1].team_name << " has won by " << (board[1].runs - board[2].runs);
			cout << " runs\n";
		}
		else
		{
			cout << team[2].team_name << " has won by " << (10 - board[2].wickets);
			cout << " wickets\n";
		}
}

/* Generate The Teams */
void generate_team(TEAM *team)
{
	int t=1;
	FILE *cfptr;
	char *file1;
	while (t < 3)
	{
		cout << "These Are The Teams That Are Available\n";
		cout << "(1) Australia\n";
		char * ausi = "ausi.cri";
		cout << "(2) West Indies\n";
		char * west = "west.cri";
		cout << "(3) Sri Lanka\n";
		char * sri = "sri.cri";
		cout << "(4) Weak Side\n";
		char * shit = "shit.cri";
		cout << "(5) England\n";
		char * eng = "eng.cri";
		cout << "Please select which side you want=>";
		int selection=100;
		while (selection >5)
		{
			cin >> selection;
			if (selection == 1)
				file1 = ausi;
			else if (selection == 2)
				file1 = west;
			else if (selection == 3)
				file1 = sri;
			else if (selection == 4)
				file1 = shit ;
			else if (selection == 5)
				file1 = eng ;
			else
				cout << "Invalid input\n=>";
		}

		char a[20];
		if ((cfptr = fopen(file1, "r")) == NULL)
			printf("File cannot be opened.\n");
		else
		{

			fscanf (cfptr, "%s\n", a);
			strcpy (team[t].team_name,a);
			int i;
			for (i=1; i < 12; i++)
			{
				char pname[20];
				int batting_stat, bowling_stat, field_stat;
				fscanf (cfptr, "%s %d %d %d\n", pname, &batting_stat, &bowling_stat,
						&field_stat);
				team[t].indi[i].name_of_player(pname);
				team[t].indi[i].fix_stat(batting_stat, bowling_stat, field_stat);

			}

		}
		t++;
	}
}

/* Batting */
int simulate_match(TEAM team[], scoreboard board[])
{
	srand((unsigned)time(NULL));
	int i,b = 1, o = 2, innings = 0, win =1;
	int ones=0, twos=0, threes=0, fours=0, sixes=0, nothings=0;
	while (innings < 2)
	{
		int batter=1, batter2=2, bowler=11, bowler2=10;
		for (i=0; i < 300; i++)
		{
			int x=10000, temp, repeats;
			for (repeats = (11 - team[o].indi[bowler].bow_stat); repeats >= 0; repeats--)
			{
				temp = (rand() % ((team[b].indi[batter].bat_stat) * 100));

				if (temp < x)
					x = temp;
			}

			/* Batsman is out. */
			if (((x > 0) && (x < 5) && (team[b].indi[batter].bat_stat < 5)) ||
					((x > 599) && (x < 800)))
			{
				int how_out, fielder=0, thr;
				how_out = (x % 15) + 1;
				if (how_out <= 5)
				{
					fielder = (1 + (rand() % 11));
					thr = (rand() % (11-team[o].indi[fielder].field_stat));
					if ((thr == 0) || (thr == 1))
					{
						board[b].update_wick();
						team[o].indi[bowler].update_wickets();
						team[b].indi[batter].update_out(how_out, bowler, fielder);
						if (batter > batter2)
							batter++;
						else
							(batter = batter2 + 1);
						if (batter == 12)
							i = 301;
					}
				}
				else
				{
					board[b].update_wick();
					team[o].indi[bowler].update_wickets();
					team[b].indi[batter].update_out(how_out, bowler, fielder);
					if (batter > batter2)
						batter++;
					else
						(batter = batter2 + 1);
					if (batter == 12)
						i = 301;
				}
			}

			/* Batsman hits Six. */
			else if ((x == 9) || (x == 5))
			{
				board[b].update_runs(6);
				team[b].indi[batter].update_bat_runs(6);
				team[o].indi[bowler].update_bow_runs(6);
				sixes++;
			}

			/* Batsman hits four. */
			else if ((x>5) && (x<9))
			{
				board[b].update_runs(4);
				team[b].indi[batter].update_bat_runs(4);
				team[o].indi[bowler].update_bow_runs(4);
				fours++;
			}

			/* Batsman hits three. */
			else if (((x<801) && (x>749)) || ((x<401) && (x>300)))
			{
				int temp;
				board[b].update_runs(3);
				team[b].indi[batter].update_bat_runs(3);
				team[o].indi[bowler].update_bow_runs(3);
				temp = batter;
				batter= batter2;
				batter2 = temp;
				threes++;

			}

			/* Batsman hits two. */
			else if ((x>9) && (x<25))
			{
				board[b].update_runs(2);
				team[b].indi[batter].update_bat_runs(2);
				team[o].indi[bowler].update_bow_runs(2);
				twos++;
			}

			/* Batsman hits one. */
			else if ((x>49) && (x<101))
			{
				int temp;
				board[b].update_runs(1);
				team[b].indi[batter].update_bat_runs(1);
				team[o].indi[bowler].update_bow_runs(1);
				temp = batter;
				batter= batter2;
				batter2 = temp;
				ones++;
			}

			else
				nothings++;



			/* Changes at the end of the over. */
			if ((i % 6) == 0)
			{
				int temp;
				board[b].update_overs();
				team[o].indi[bowler].update_over_bowled();
				temp = bowler;
				bowler = bowler2;
				bowler2= temp;
				if (team[o].indi[bowler2].overs == 10)
				{
					if (bowler > bowler2)
						bowler2--;
					else
						(bowler2 = (bowler - 1));
				}
			}
			if ((b == 2) && (board[1].runs < board[2].runs))
			{
				win = 2;
				i = 400;
			}
		}
		innings++;
		b = 2; o = 1;
	}
	return win;
}
