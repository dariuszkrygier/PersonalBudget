#include "UsersFile.h"


void UsersFile :: saveUserToFile(User user) {
    CMarkup xml;

    bool fileExists = xml.Load(usersFileName);

    if (!fileExists) {
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem ("User");
    xml.IntoElem();
    xml.AddElem( "Id", AuxiliaryMethods :: convertIntToString(user.getId()) );
    xml.AddElem( "Name", user.getName() );
    xml.AddElem( "Surname", user.getSurname() );
    xml.AddElem( "Login", user.getLogin() );
    xml.AddElem( "Password", user.getPassword() );

    xml.Save (usersFileName);
}

vector <User> UsersFile :: loadUsersFromFile() {
    User user;
    vector <User> users;
    CMarkup xml;
    xml.Load( usersFileName );
    //xml.ResetPos();

    xml.FindElem(); // root Users element
    xml.IntoElem(); // inside Users
    while ( xml.FindElem("User") ) {
        xml.IntoElem();
        xml.FindElem( "Id" );
        int nQty = atoi( MCD_2PCSZ(xml.GetData()) );
        user.setId (nQty);
        xml.FindElem( "Name" );
        MCD_STR name = xml.GetData();
        user.setName (name);
        xml.FindElem( "Surname" );
        MCD_STR surname = xml.GetData();
        user.setSurname (surname);
        xml.FindElem( "Login" );
        MCD_STR login = xml.GetData();
        user.setLogin (login);
        xml.FindElem( "Password" );
        MCD_STR password = xml.GetData();
        user.setPassword (password);
        users.push_back(user);
        xml.OutOfElem();
    }
    return users;
}

void UsersFile :: saveAllUsersToFile(vector <User> &users) {
    CMarkup xml;


    xml.AddElem("Users");
    xml.FindElem();
    xml.IntoElem();

    vector <User>::iterator itrEnd = --users.end();
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        xml.AddElem ("User");
        xml.IntoElem();
        xml.AddElem( "Id", itr -> getId() );
        xml.AddElem( "Name", itr -> getName() );
        xml.AddElem( "Surname", itr -> getSurname() );
        xml.AddElem( "Login", itr -> getLogin() );
        xml.AddElem( "Password", itr -> getPassword() );
        xml.Save (usersFileName);
        xml.OutOfElem();
    }

}
