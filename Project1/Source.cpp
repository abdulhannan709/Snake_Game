#include<iostream>
#include<conio.h>
#include<fstream>
#include<ctime>

using namespace std;

void printMap(const int mapwidth, const int mapheight, int size);
void initMap(const int mapwidth, const int mapheight, int size);
void move(int dx, int dy, const int mapwidth, const int mapheight, int size, int mode);
void update(const int mapwidth, const int mapheight, const int size);
void input_snake(char key);
void generateFood(int mapwidth, int mapheight, int size);
char getMapValue(int value);

int map[400];
int headxpos;
int headypos;
int direction;
int food = 3, score=0, mode;
bool running;

int main()
{
	const int mapwidth = 20;
	const int mapheight = 20;
	const int size = mapwidth * mapheight;
	int  ezscr=0, mdscr=0, hrdscr=0;
	char play;
	ifstream fin;
	ofstream fout;
	fin.open("easy.txt");
	fin>>ezscr;
	fin.close();
	fin.open("medium.txt");
	fin>>mdscr;
	fin.close();
	fin.open("hard.txt");
	fin>>hrdscr;
	fin.close();
	
for(int i=0; i<100; i++)
{
	cout<<"\n\n\n\n\n\n\n\n";
if(i>=0 && i<10)
{
	cout<<"\t\t\t\tStarting. . ."<<endl;
	cout<<"\t\t\t\t!!.................."<<endl;
	cout<<"\t\t\t\t"<<i<<"%";
}
if(i>=10 && i<20)
{
	cout<<"\t\t\t\tStarting. . ."<<endl;
	cout<<"\t\t\t\t!!!!................"<<endl;
	cout<<"\t\t\t\t"<<i<<"%";
}
if(i>=20 && i<30)
{
	cout<<"\t\t\t\tStarting. . ."<<endl;
	cout<<"\t\t\t\t!!!!!!.............."<<endl;
	cout<<"\t\t\t\t"<<i<<"%";
}
else if(i>=30&& i<40)
{
	cout<<"\t\t\t\tLoading. . ."<<endl;
		cout<<"\t\t\t\t!!!!!!!!............"<<endl;
	cout<<"\t\t\t\t"<<i<<"%";

}
else if(i>=40&& i<50)
{
	cout<<"\t\t\t\tLoading files: easy. . ."<<endl;
		cout<<"\t\t\t\t!!!!!!!!!!.........."<<endl;
	cout<<"\t\t\t\t"<<i<<"%";

}
else if(i>=50&& i<60)
{
	cout<<"\t\t\t\tLoading files: medium. . ."<<endl;
		cout<<"\t\t\t\t!!!!!!!!!!!!........"<<endl;
	cout<<"\t\t\t\t"<<i<<"%";

}
else if(i>=60&& i<70)
{
	cout<<"\t\t\t\tLoading files: hard. . ."<<endl;
		cout<<"\t\t\t\t!!!!!!!!!!!!!!......"<<endl;
	cout<<"\t\t\t\t"<<i<<"%";
}
else if(i>=70&& i<80)
{
	cout<<"\t\t\t\twait a few seconds. . ."<<endl;
		cout<<"\t\t\t\t!!!!!!!!!!!!!!!!...."<<endl;
	cout<<"\t\t\t\t"<<i<<"%";
}

else if(i>=80&& i<90)
{
	cout<<"\t\t\t\twait a few seconds. . ."<<endl;
		cout<<"\t\t\t\t!!!!!!!!!!!!!!!!!!.."<<endl;
	cout<<"\t\t\t\t"<<i<<"%";
}
else if(i>=90&& i<100)
{
	cout<<"\t\t\t\twait a few seconds. . ."<<endl;
		cout<<"\t\t\t\t!!!!!!!!!!!!!!!!!!!!"<<endl;
	cout<<"\t\t\t\t"<<i<<"%";
}
_sleep(15);
system("cls");
}
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\Loading complete. . ."<<endl;
		cout<<"\t\t\t\t!!!!!!!!!!!!!!!!!!!!"<<endl;
	cout<<"\t\t\t\t100"<<"%";
	_sleep(25);
	system("cls");

cout<<"\t\t-:RULES:-"<<endl;
cout<<"Every time you eat the food:\n1) New food is generated on random position."<<endl;
cout<<"2) score is updated"<<endl;
cout<<"3) Tail size is inceased"<<endl;
cout<<endl;
cout<<"\t\t!!!WARNING!!!"<<endl;
cout<<"1) Snake head must not touch the border of the plane"<<endl;
cout<<"2) Snake head must not touch its tail"<<endl;
cout<<endl;
cout<<"BEAT THE HIGHEST SCORE IF YOU CAN"<<endl;
cout<<endl;
system("pause");
system("cls");

cout<<"Game has three difficulty levels:"<<endl;
cout<<"Easy (highest score = "<<ezscr<<" )"<<endl;
cout<<"Medium (highest score = "<<mdscr<<" )"<<endl;
cout<<"Hard (highest score = "<<hrdscr<<" )"<<endl;
cout<<endl;
cout<<"In EASY level game have SLOW speed."<<endl;
cout<<"In MEDIUM level game have SLIGHTLY FASTER speed."<<endl;
cout<<"In HARD level game have FASTEST speed."<<endl;
cout<<endl;
system("pause");
system("cls");
do{
	for(int i=0; i<400; i++)
		map[i]=0;

cout<<"Enter game mode:"<<endl;
cout<<"1 => EASY"<<endl;
cout<<"2 => MEDIUM"<<endl;
cout<<"3 => HARD"<<endl;
cin>>mode;
system("cls");

cout<<"\t\tINSTRUCTIONS"<<endl;
cout<<"Use A, S, D, and W keys to move snake head."<<endl;
cout<<"W => to move UP"<<endl;
cout<<"S => to move DOWN"<<endl;
cout<<"A => to move LEFT"<<endl;
cout<<"D => to move RIGHT"<<endl;
cout<<endl;
system("pause");
system("cls");

if(mode==1)
{
	initMap(mapwidth,mapheight,size);
    running = true;
    while (running) 
	{
		if(kbhit())
		input_snake(getch());
		update(mapwidth,mapheight,size);
		system("cls");
		printMap(mapwidth,mapheight,size);
        _sleep(100);
    }
    cin.ignore();
if(score>ezscr)
{
cout<<"\t\t\tHIGHEST SCORE"<<endl;
system("pause");
	fout.open("easy.txt");
	fout<<score;
	fout.close();
}
}

else if(mode==2)
{
	initMap(mapwidth,mapheight,size);
    running = true;
    while (running) 
	{
		if(kbhit())
		input_snake(getch());
		update(mapwidth,mapheight,size);
		system("cls");
		printMap(mapwidth,mapheight,size);
        _sleep(10);
    }
    cin.ignore();
if(score>mdscr)
{
cout<<"\t\t\tHIGHEST SCORE"<<endl;
system("pause");
	fout.open("medium.txt");
	fout<<score;
	fout.close();
}
}

else if(mode==3)
{
	initMap(mapwidth,mapheight,size);
    running = true;
    while (running) 
	{
		if(kbhit())
		input_snake(getch());
		update(mapwidth,mapheight,size);
		system("cls");
		printMap(mapwidth,mapheight,size);
    }
    cin.ignore();
if(score>hrdscr)
{
cout<<"\t\t\tHIGHEST SCORE"<<endl;
system("pause");
fout.open("hard.txt");
	fout<<score;
	fout.close();
}
}
system("cls");
cout<<"\n\n\n";
cout<<"\t\t!!!GAMEOVER!!!"<<endl;
cout<<"\t\tYour score = "<<score<<endl;
cout<<"To PLAY AGAIN  press 'Y' \n OR"<<endl;
cout<<"Press any key to EXIT"<<endl;
cin>>play;
system("cls");
}while(play=='y'|| play=='Y');
return 0;
}

void input_snake(char key) 
{	
    switch (key) 
	{
    case 'w':
         direction = 0;
        break;
    case 'd':
         direction = 1;
        break;
    case 's':
         direction = 2;
        break;
    case 'a':
         direction = 3;
        break;
	}
}

void move(int dx, int dy, const int mapwidth, const int mapheight, int size, int mode) 
{
    int newx = headxpos + dx;
    int newy = headypos + dy;

    if (map[newx + newy * mapwidth] == -2)
	{
        food++;
		score+=mode;
		generateFood(mapwidth,mapheight,size);
    }

	else if (map[newx + newy * mapwidth] != 0) 
	{
        running = false;
    }
    headxpos = newx;
    headypos = newy;
    map[headxpos + headypos * mapwidth] = food + 1;
}

void generateFood(int mapwidth, int mapheight, int size) 
{
	int x = 0;
    int y = 0;
    do {
        x = rand() % (mapwidth - 2) + 1;
        y = rand() % (mapheight - 2) + 1;
    } while (map[x + y * mapwidth] != 0);
    map[x + y * mapwidth] = -2;
}

void update(const int mapwidth, const int mapheight, const int size) 
{
    switch (direction) 
	{
	case 0:
		move(-1, 0, mapwidth, mapheight, size, mode);
        break;
	case 1:
		move(0, 1,mapwidth,mapheight,size, mode);
        break;
	case 2: 
		move(1, 0,mapwidth,mapheight,size, mode);
        break;
	case 3:
		move(0, -1,mapwidth,mapheight,size, mode);
        break;
    }

    for (int i = 0; i < size; i++) 
	{
        if (map[i] > 0) 
		map[i]--;
    }
}

void initMap(const int mapwidth, const int mapheight, int size)
{
    headxpos = mapwidth / 2;
    headypos = mapheight / 2;
    map[headxpos + headypos * mapwidth] = 1;
    for (int x = 0; x < mapwidth; ++x) 
	{
        map[x] = -1;
        map[x + (mapheight - 1) * mapwidth] = -1;
    }

    for (int y = 0; y < mapheight; y++) 
	{
        map[0 + y * mapwidth] = -1;
        map[(mapwidth - 1) + y * mapwidth] = -1;
    }
	generateFood(mapwidth,mapheight,size);
}

void printMap(const int mapwidth, const int mapheight, int size)
{
    for (int x = 0; x < mapwidth; ++x) 
	{
        for (int y = 0; y < mapheight; ++y) 
		{
            cout << getMapValue(map[x + y * mapwidth]);
        }
        cout << endl;
    }
}

char getMapValue(int value)
{
    if (value > 0) 
	return 'o';

    switch (value) 
	{
    case -1:
		return 'X';
    case -2:
		return 'O';
    }
}