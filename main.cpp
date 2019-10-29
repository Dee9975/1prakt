//Matiss Kalnins P2-4


//Praktiskais darbs pie datora - klase Auto, kas apraksta automobīli
//
//•Jāsatur minimums 3 privātie atribūti, viens no tiem –
//  float vidBenzinaPaterins;  //uz 100 km
//
//•Definējiet publiskās klases metodes:
//•Pievienot iekšējās set / get metodes (katram atribūtam atsevišķi),
//•Aprakstīt un nodefinēt ārējo metodi printAutoData( )
//•Pievienojiet ārējo metodi float getCelaBenzins( float km )  kas aprēķina paredzamo benzīna patēriņu uz norādīto kilometru skaitu
//•Norādiet konstantās metodes
//•Izveidot globālo klases objektu mansAuto un norādi skolasAuto
//•Funkcijā main() izveidot dinamisko objektu ar norādi skolasAuto
//•Izmantojot abus šos objektus izsaukt visas klases metodes
//•Iznīcināt dinamisko mainīgo
//Papildieniet klasi Auto ar konstruktoru bez parametriem, kas piešķir klases atribūtiem vērtību pēc noklusējuma
//•Pārslogojiet šo konstruktoru, lai tam būtu viens atribūts un tas piešķirtu šī atribūta vērtību laukam vidBenzinaPaterins. Izmantojiet norādi this
//•Pievienojiet destruktoru, kas izdrukā mašīnas datus un paziņo, ka tā tiek norakstīta (beigās – cin.get())
//•Main funkcijā izveidojiet vēl vienu dinamisko objektu, izmantojot otro konstruktoru

#include <iostream>
#include <string>

class Car {
private:
    float avgFuelConsumption;
    std::string color;
    std::string maker, model;
public:
    Car() {
        this->avgFuelConsumption = 0;
        this->color = "Color";
        this->maker = "Maker";
        this->model = "Model";
    }
    Car(float avgFuel, std::string color, std::string maker, std::string model) {
        this->avgFuelConsumption = avgFuel;
        this->color = color;
        this->maker = maker;
        this->model = model;
    }
    Car(float avgFuelConsumption ) {
        this->avgFuelConsumption = avgFuelConsumption;
    }

    void printAutodata();
    float getFuelUsed(float km);

    float getAFC() {
        return avgFuelConsumption;
    }

    std::string getColor() {
        return color;
    }
    std::string getMaker() {
        return maker;
    }
    std::string getModel() {
        return model;
    }

    void setAFC(float a) {
        avgFuelConsumption = a;
    }
    void setColor(std::string c) {
        color = c;
    }
    void setMaker(std::string m) {
        maker = m;
    }
    void setModel(std::string m) {
        model = m;
    }

    ~Car() {
        std::cout << "Auto ticis norakstits: " << std::endl;
        printAutodata();
    }
};

void Car::printAutodata() {
    std::cout << "-----------------------" << std::endl;
    std::cout << "Auto marka: " << this->maker << std::endl;
    std::cout << "Auto videjais degvielas paterins: " << this->avgFuelConsumption << std::endl;
    std::cout << "Auto modelis: " << this->model << std::endl;
    std::cout << "Auto color: " << this->color << std::endl;
    std::cout << "-----------------------" << std::endl;
}

float Car::getFuelUsed(float km) {
    return (this->avgFuelConsumption * km) / 100;
}

Car mansAuto;

int main() {
    Car *skolasAuto;
    skolasAuto = new Car(3.4);

    mansAuto.setMaker("VW");
    mansAuto.setModel("Touran");
    mansAuto.setAFC(3.2);
    mansAuto.setColor("Red");

    float afc = mansAuto.getAFC();
    std::string color = mansAuto.getColor();
    std::cout << "MansAuto, printAutoData()" << std::endl;
    mansAuto.printAutodata();

    float fuel = mansAuto.getFuelUsed(300);

    std::cout << "-----------------------------" << "\n"
    << "MansAuto Dati: " << "\n"
    << "Avarage Fuel Consumption: " << afc << "\n"
    << "Color: " << color << "\n"
    << "Fuel used: " << fuel << "\n"
    << "-----------------------------" << std::endl;
    std::cout << "skolasAuto Destructor:" << std::endl;

    Car *kompanijasAuto = new Car(3.2, "Red", "VW", "Polo");
    delete kompanijasAuto;

    delete skolasAuto;
}