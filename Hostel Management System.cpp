#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

class hostel
{
    int sid[100],taka[100],c;
    string ch[100];
public:

    hostel()
    {
        this->c=0;
    }
    //software information function
    void header();
    void welcome();
    int idposition(int sid);
    void program_close();


    //report
    void available_room();


    //starting room engin
    vector<int>rnumber;
    vector<int>rfloor;
    vector<int>rcategory;

    //starting room function
    void get_roominfo();
    void add_room();
    void update_room();
    void display_room();
    void search_room();
    void delete_room();
    int room_position(int n);
    int greator_rnum();
    int cheikh_room(int roomid);
    int avi_room(int roomid);
    void room_close();

    //strarting student information enjin
    vector<int> studentid;
    vector<string>studentname;
    vector<int>studentroom;

    //student information function
    int student_id_maker();
    void get_studentinfo();
    void display_student();
    void search_student();
    void update_student();
    void add_student();
    void delete_student();
    void student_clear();
    void student_insert();
//end student information function

//strating room allotment

};

void hostel::program_close()
{
    student_clear();
    student_insert();
    room_close();
}


//room dashboard panel starting===================================================================


//display room info(display all student  information form array)=========================
void hostel::display_room()
{

    printf("\t\t\t\t\t\tDisplay All Room Information\n");
    printf("\t\t\t\t\t============================================");
    printf("\n\n");
    printf("\t\t   Room Number\t\t Floor Number \t\t Room Category \t\t Room Status\n");
    printf("\t\t  ============\t\t===============\t\t=============\t\t==============\n\n");
    for(int j=0; j<rnumber.size(); j++)
    {
        cout << right  << setw(25) <<  this->rnumber[j] << right << setw(22) << this->rfloor[j]  << setw(22) << rcategory[j] << setw(27) << "Avilabol"<< '\n';
    }
    cout << "\n";
}//end display_room function============================


//get room_info===================================================================p01
void hostel::get_roominfo()
{
    int flag=0;
    int rnum,rfloor1,rcat;
    int c1=0;
    ifstream info;
    info.open("room.txt");
    while(!info.eof())
    {
        string name1[2],name2[2],name3[3];

        if(c1==0 || c1==1)
        {
            info >> name1[0] >> name2[0] >> name3[0];
        }
        else
        {
            info >> rnum >> rfloor1 >> rcat;
            rnumber.push_back(rnum);
            rfloor.push_back(rfloor1);
            rcategory.push_back(rcat);
        }
        c1++;
    }
    info.close();
}
//end get room info===============================================================end p01



//add room function(add room in arry frmo this function)===============================================================p02
void hostel::add_room()
{


    printf("\t\t\t\t\t\t\tAdded New Room\n");
    printf("\t\t\t\t\t============================================");

    printf("\n\n");
    int num,floor,category;
    num=greator_rnum();
    cout << "\t\t\t\t\t\tNew Room Number is: " << num << "\n";
    cout <<"\t\t\t\t\t\tEnter New Room Floor: ";
    cin >> floor;
    cout << "\t\t\t\t\t\tEnter New Room Category Number: ";
    cin >> category;
    rnumber.push_back(num);
    rfloor.push_back(floor);
    rcategory.push_back(category);
    cout << "\n\t\t\t\t\t\tSucessfully Added New Data\n\n";
}//end this function=============================================================end p02




//start update room function========================================================
void hostel::update_room()
{
    printf("\t\t\t\t\t\tUpdate Room Information\n");
    printf("\t\t\t\t\t=========================================");

    printf("\n\n");
    int found=0;
    int num,floor,category;
    cout << "\t\t\t\t\t\tEnter Room Number: ";
    while(cin >> num)
    {
        if(num==-1)break;
        int i,position,found=0;
        position=room_position(num);

        if(position!=-1)
        {
            cout << "\t\t\t\t\t\tEnter Room Floor: ";
            cin >> floor;
            rfloor[position]=floor;
            cout << "\t\t\t\t\t\tEnter Room Category:";
            cin >> category;
            rcategory[position]=category;
            cout << "\n\t\t\t\t\tSucessfully Update Room Information Info\n\n";
            found=1;
        }
        else
        {
            cout << "\n\t\t\t\t\tSorry No user id found for name update\n\n";
            cout << "\t\t\t\t\tEnter Room Number or exit press (-1): ";
        }
        if(found==1)break;

    }
}//end room function============================================================



//delete room=================================================================
void hostel::delete_room()
{

    printf("\t\t\t\t\t\t\tDelete Room Information\n");
    printf("\t\t\t\t\t============================================");

    printf("\n\n");

    int rid,position,i,j,found=0;
    vector<int>rnumber1,rfloor1,rcategory1;
    cout << "\t\t\t\t\t\tEnter Room Number: ";
    while(cin >> rid)
    {
        if(rid==-1)break;
        position=room_position(rid);
        if(position!=-1)
        {
            found=1;
            for(i=0; i<position; i++)
            {
                rnumber1.push_back(rnumber[i]);
                rfloor1.push_back(rfloor[i]);
                rcategory1.push_back(rcategory[i]);
            }
            for(i=position; i<rnumber.size()-1; i++)
            {
                rnumber1.push_back(rnumber[i+1]);
                rfloor1.push_back(rfloor[i+1]);
                rcategory1.push_back(rcategory[i+1]);
            }
            rnumber=rnumber1;
            rfloor=rfloor1;
            rcategory=rcategory1;
            cout << "\t\t\t\t\tSucesully Delete This Room\n\n";
        }
        else
        {

            cout << "\t\t\t\t\t\tRoom Number Is Not Found\n";
            cout << "\t\t\t\t\t\tEnter Room Id or exit pres (-1): ";
        }
        if(found==1)break;
    }
}//end delete room function==================================


//start search room=====================================
void hostel::search_room()
{
    printf("\t\t\t\t\t\tSearch Room Information\n");
    printf("\t\t\t\t\t============================================");

    printf("\n\n");

    int i,found=0,num,position,j;
    cout << "\t\t\t\t\t\tEnter Room Number: ";
    while(cin >> num)
    {
        if(num==-1)break;
        position=room_position(num);
        j=position;
        if(position!=-1)
        {

            printf("\n\t\t   Room Number\t\t Floor Number \t\t Room Category \t\t Room Status\n");
            printf("\t\t  ============\t\t===============\t\t=============\t\t==============\n\n");
            cout << right  << setw(25) << this->rnumber[j] << right << setw(22) << this->rfloor[j]  <<
                 setw(22) << rcategory[j] << setw(30) << "Avilavol"<< '\n';
            found=1;
            cout << "\n";
        }
        else
        {
            cout << "\n\t\t\t\t\tSorry Room Number is not found\n\n";
            cout << "\t\t\t\t\tEnter Room Number or exit press (-1): ";

        }
        if(found==1)break;
    }
}//end search room information==========================================================================


//start room_close function()=======================================================
void hostel::room_close()
{

    ofstream sclear ("room.txt", std::ios::out | std::ios::trunc);
    sclear.close();

    int i;
    ofstream sinsert;
    sinsert.open("room.txt", std::ios_base::app);
    for(i=0; i<rnumber.size()+2; i++)
    {
        if(i==0)
        {
            sinsert << "Rnum" << " " << "Floor"  << " " << "Category"<<  endl;
        }
        else if(i==1)
        {
            sinsert << "--" << " ------------" << " " << "------------";
        }
        else
        {
            sinsert << "\n" << rnumber[i-2] << " " << rfloor[i-2] << " " << rcategory[i-2];
        }
    }
    sinsert.close();
}
//end room_close() function=====================================================================



//available room cheikh========================================================================
int hostel::avi_room(int num)
{
    int res=0,i;
    for(i=0; i<studentroom.size(); i++)
    {
        if(num==studentroom[i])
        {
            res=1;
            break;
        }
    }
    return res;
}
//end available room===========================================================================


//start available room function ======================================================================
void hostel::available_room()
{
    int i,status;

    printf("\t\t\t\t\t\tAll Available Room Information\n");
    printf("\t\t\t\t\t============================================");
    printf("\n\n");

    printf("\t\t   Room Number\t\t Floor Number \t\t Room Category \t\t Room Status\n");
    printf("\t\t  ============\t\t===============\t\t=============\t\t==============\n\n");
    for(i=0; i<rnumber.size(); i++)
    {
        int j=i;
        status=avi_room(rnumber[i]);
        if(status==0)
        {
            cout << right  << setw(25) <<  this->rnumber[j] << right << setw(22) << this->rfloor[j]  << setw(22) << rcategory[j] << setw(28) << "Avilabol"<< '\n';
        }
    }
}
//end available room function========================================================================


//cheikh room====================================================================
int hostel::cheikh_room(int num)
{
    int i,found=0;
    for(i=0; i<rnumber.size(); i++)
    {
        if(rnumber[i]==num)
        {
            found=i;
            break;
        }
    }
    return found;
}
//end cheikh room============================================================================




//greator room number===============================================================================

int hostel::greator_rnum()
{
    sort(rnumber.begin(), rnumber.end(),greater<int>());
    return rnumber[0]+1;
}
//end room number function================================================================



//room position=====================================
int hostel::room_position(int num)
{
    int res=-1,found=0,i;
    for(i=0; i<rnumber.size(); i++)
    {
        if(rnumber[i]==num)
        {
            res=i;
            break;
        }
    }
    return res;
}
//end room position==================================


//student_clear() function start=====================================
void hostel::student_clear()
{
    ofstream sclear ("information.txt", std::ios::out | std::ios::trunc);
    sclear.close();
}
//end student clear function=========================================

//starting student_insert() function======================================
void hostel::student_insert()
{
    int i;
    ofstream sinsert;
    sinsert.open("information.txt", std::ios_base::app);
    for(i=0; i<studentid.size()+2; i++)
    {
        if(i==0)
        {
            sinsert << "Id" << " " << "StudentName"  << " " << "Room"<<  endl;
        }
        else if(i==1)
        {
            sinsert << "--" << " ------------" << " " << "-----";
        }
        else
        {
            sinsert << "\n" << studentid[i-2] << " " << studentname[i-2] << " " << studentroom[i-2];
        }
    }
    sinsert.close();
}
//end student insert() function====================================


//position cheikh========================================
int hostel::idposition(int sid)
{

    int i,position=-1;
    for(i=0; i<studentid.size(); i++)
    {
        if(studentid[i]==sid)
        {
            position=i;
            break;
        }
    }
    return position;
}//end position cheikh========================================


//start get_studentinfo() function=============================
void hostel::get_studentinfo()
{
    int c1=0;
    int sid1,rnumber1;
    string sname;
    int flag=0;
    ifstream info;
    info.open("information.txt");
    while(!info.eof())
    {
        string name1[2],name2[2],name3[2];

        if(c1==0 || c1==1)
        {
            info >> name1[0] >> name2[0] >> name3[0];
        }
        else
        {
            info >> sid1>> sname >> rnumber1;
            studentid.push_back(sid1);
            studentname.push_back(sname);
            studentroom.push_back(rnumber1);
        }
        sname.clear();
        c1++;
    }
    info.close();
}
//end get_studentinfo() function====================================


//starting delete_student() function===============================
void hostel::delete_student()
{
    printf("\t\t\t\t\t\tDelete Student Information\n");
    printf("\t\t\t\t\t============================================");

    printf("\n\n");

    int rid,position,i,j,found=0;
    vector<int>sid,room;
    vector<string>sname;
    cout << "\t\t\t\t\t\tEnter Student Number: ";
    while(cin >> rid)
    {
        if(rid==-1)break;
        position=idposition(rid);
        if(position!=-1)
        {
            found=1;
            for(i=0; i<position; i++)
            {
                sid.push_back(studentid[i]);
                room.push_back(studentroom[i]);
                sname.push_back(studentname[i]);
            }
            for(i=position; i<studentid.size()-1; i++)
            {
                sid.push_back(studentid[i+1]);
                room.push_back(studentroom[i+1]);
                sname.push_back(studentname[i+1]);
            }
            studentid=sid;
            studentroom=room;
            studentname=sname;
            cout << "\t\t\t\t\tSucesully Delete Student Information\n\n";
        }
        else
        {

            cout << "\t\t\t\t\t\tStudent  Id Is Not Found\n";
            cout << "\t\t\t\t\t\tEnter Student Id or exit pres (-1): ";
        }
        if(found==1)break;
    }

}
//end delete student=========================================


//start update_student() function=====================================
void hostel::update_student()
{
    printf("\t\t\t\t\t\tUpdate Student Information\n");
    printf("\t\t\t\t\t=========================================");

    printf("\n\n");
    int found=0;
    int num,floor,category,rnum1;
    string sname;
    cout << "\t\t\t\t\t\tEnter Student Id: ";
    while(cin >> num)
    {
        if(num==-1)break;
        int i,position,found=0;
        position=idposition(num);

        if(position!=-1)
        {
            cout << "\t\t\t\t\t\tEnter Student Name: ";
            cin >> sname;
            studentname[position]=sname;
            cout << "\t\t\t\t\t\tEnter Room Number:";
            cin >> rnum1;
            studentroom[position]=rnum1;
            cout << "\n\t\t\t\t\tSucessfully Update Room Information Info\n\n";
            found=1;
        }
        else
        {
            cout << "\n\t\t\t\t\tSorry No user id found for name update\n\n";
            cout << "\t\t\t\t\tEnter Student Id or exit press (-1): ";
        }
        if(found==1)break;

    }
}
//end update_student() function====================================


//id greator============================================
int hostel::student_id_maker()
{

    vector<int>v;
    v=studentid;
    sort(v.begin(),v.end(),greater<int>());
    if(v.size()>0)
    {
        return v[0]+1;
    }
    else
    {
        return 1;
    }
}//id greator===========================================


//welcome screen==========================================
void hostel::welcome()
{
    int i;
    cout << "\n\n\t\t\t";
    for(i=0; i<59; i++)
    {
        cout << "*";
    }
    cout << "\n";
    cout << "\t\t\t*\t\t\t\t\t\t\t  *\n";
    cout << "\t\t\t*\t\t\tWELCOME\t\t\t\t  *\n";
    cout << "\t\t\t*\t\tHostel Management System\t\t  *\n";
    cout << "\t\t\t*\t\t\t\t\t\t\t  *\n";
    cout << "\t\t\t";
    for(i=0; i<59; i++)
    {
        cout << "*";
    }
    cout << "\n";
    system("pause");
    system("cls");
}

//add student================================================================
void hostel::add_student()
{
    int sid,rfound,found=0;
    int room;
    string name;
    sid=student_id_maker();
    cout << "\n\t\t\t\t\t Student Id is: " << sid  << "\n";
    cout << "\t\t\t\t\t Enter student name: ";
    cin >> name;
    cout << "\t\t\t\t\t Enter Room Number: ";
    while(cin >> room)
    {
        rfound=cheikh_room(room);
        if(rfound!=0)
        {
            found=1;
            break;

        }
        else
        {
            cout << "\n\t\t\t\t\tSorry Room Number is not found\n\n";
            cout << "\t\t\t\t\tAvilabol Room Number is:\n";
            cout  << "\t\t\t\t\t";
            for(int i=0; i<rnumber.size(); i++)
            {
                cout << rnumber[i] << ",";
            }
            cout << "\n\t\t\t\t\tEnter Correct Room Number: ";
        }
    }
    if(found==1)
    {
        studentid.push_back(sid);
        studentname.push_back(name);
        studentroom.push_back(room);
        cout << "\n\t\t\t\t\tSucessfull Student Information Add\n";
    }
}

//set header===================================================================
void hostel::header()
{
    printf("\n");
    printf("\t\t\t\t\t\tHostel Management Dashboard\n");
    printf("\t\t\t\t\t============================================");

    printf("\n\n");
    printf("\t\t      Student Info\t\t\t Room Info\t\t\t    Report\n");
    printf("\t\t    ==================\t\t      ================\t\t\t  ============\n\n");
    printf("\t\t11) All Student Information    |     21) All Room Information    |      31) Avilabol Room\n");
    printf("\t\t12) Add Information\t       |     22) Add Room\t \t |\t32) Student Info\n");
    printf("\t\t13) Search Information\t       |     23) Search Room\t \t \n");
    printf("\t\t14) Edit Information\t       |     24) Edit Room\t \t \t\n");
    printf("\t\t15) Delete Information\t       |     25) Delete Room\t\t \n\n");
    printf("\t\t\t\t\t0) Press '0' for Quit This Software\n\n");

}
//end set_header


//display student information=========================================
void hostel::display_student()
{
    printf("\t\t\t\t\t\tDisplay All Student Information\n");
    printf("\t\t\t\t\t============================================");
    printf("\n\n");


    printf("\t\t   Student Id\t\t Student Name \t\t Room Number \t\t Floor Number\n");
    printf("\t\t  ============\t\t===============\t\t=============\t\t==============\n\n");


    for(int j=0; j<studentid.size(); j++)
    {
        int res=1;
        for(int i=0; i<rnumber.size(); i++)
        {
            if(studentroom[j]==rnumber[i])
            {
                res=rfloor[i];
                break;
            }
        }
        cout << right  << setw(25)  << this->studentid[j] << right << setw(25) << this->studentname[j]  << setw(22) << studentroom[j] << setw(24) << res<< '\n';

    }
    cout << "\n";
}

//search student info============================================
void hostel::search_student()
{
    printf("\t\t\t\t\t\tSearch Student Information\n");
    printf("\t\t\t\t\t============================================");
    printf("\n\n");


    int i,found=0,num,position,j;
    cout << "\t\t\t\t\t\tEnter Student Id: ";
    while(cin >> num)
    {
        if(num==-1)break;
        position=idposition(num);
        j=position;
        if(position!=-1)
        {

            printf("\n\t\t   Room Number\t\t Floor Number \t\t Room Category \t\t Room Status\n");
            printf("\t\t  ============\t\t===============\t\t=============\t\t==============\n\n");

            int res=1;
            for(i=0; i<rnumber.size(); i++)
            {
                if(studentroom[j]==rnumber[i])
                {
                    res=rfloor[i];
                    break;
                }
            }
            cout << right  << setw(25)  << this->studentid[j] << right << setw(25) << this->studentname[j]  << setw(22) << studentroom[j] << setw(24) << res<< '\n';

            found=1;
            cout << "\n";
        }
        else
        {
            cout << "\n\t\t\t\t\tSorry Student Id is not found\n\n";
            cout << "\t\t\t\t\tEnter Room Number or exit press (-1): ";
        }
        if(found==1)break;
    }
}
//end search student info==============================================


//start main function============================================
int main()
{

    int n,pre,flag=0;

    hostel ob1;

    ob1.get_roominfo();
    ob1.get_studentinfo();

    ob1.welcome();
    ob1.header();

    printf("\t\t\t\tPlease Select Any Option: ");


    while(cin >> n)
    {
        pre=n;
        printf("\n\t==========================================================================================================\n\n");
        flag=0;
        //student option
        if(pre==11)
        {

            ob1.display_student();
        }
        else if(pre==12)
        {
            ob1.add_student();

        }
        else if(pre==13)
        {
            ob1.search_student();
        }

        else if(pre==14)
        {
            ob1.update_student();
        }
        else if(pre==15)
        {
            ob1.delete_student();
        }

        //ens student option

        else if(pre==21)
        {
            ob1.display_room();
        }
        else if(pre==22)
        {
            ob1.add_room();
        }
        else if(pre==23)
        {
            ob1.search_room();
        }
        else if(pre==24)
        {
            ob1.update_room();
        }
        else if(pre==25)
        {
            ob1.delete_room();
        }
        else if(pre==31)
        {
            ob1.available_room();
        }
        else if(pre==32)
        {
            ob1.search_student();
        }

        //end room object

        else if(pre==0)
        {
            ob1.program_close();
            break;
        }
        else if(pre==1)
        {
            flag=1;
            ob1.header();
        }
        else
        {
            flag=1;
            printf("\t\t\t\t\t\tYou Press Wrong Option\n\n");
            ob1.header();
        }

        if(flag!=1)
            printf("\n\t\t\t\tAre You Want To See Dashboard if Yes) 1 or No) 0 : ");
        else     printf("\t\t\t\tPlease Select Any Option: ");

    }
    return 0;
}
//end main fubction
