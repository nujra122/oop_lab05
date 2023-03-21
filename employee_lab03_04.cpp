#include<iostream>
#include<string.h>

// жирийн ажилтан болон захирал гэх албан тушаалтаны цалинг define preprocessor - оор хялбархан өөрчлөх үүднээс тодорхойлно.
// нэг цагийн цалингийн хэмжээг тодорхойлно.
#define tsalin_defined 3000
#define zahiral_tsalin_defined 1000

using namespace std;
// гараас хэдэн объект үүсгэхийг асууна, хүснэгтийн хэмжээг тодорхойлох хувьсагч
int number;

// employee class үүсгэнэ
class employee{
    // эмзэг мэдээлэл, class - аас гадна талаас хандахыг зөвшөөрөхгүй байх үүднээс private access specifier ашиглана.    // хандалтын түвшин
    private:
        int dugaar;
        char ner[20];
        char alban_tushaal[10];
        float ajillasan_tsag;
        float tsalin_zahiral();
    // public төрөлтэй гишүүн өгөгдлүүд, функцуудыг дуудаж ажиллуулах тул эмзэг мэдээлэл бус гээд public access specifier ашиглана.    
    public:
        void utga_onooh();
        void garaas_utga_avah();
        void delgetsend_hevleh();
        float tsalin();

        // параметртэй байгуулагч функц
        employee(int id, char name[], char position[], float work_hour){
            dugaar = id;
            strcpy(ner, name);
            strcpy(alban_tushaal, position);
            ajillasan_tsag = work_hour;
        }
        // анхдагч байгуулагч
        employee(){
            dugaar = 0;
            strcpy(ner, "");
            strcpy(alban_tushaal, "ajiltan");
            ajillasan_tsag = 0;
        }
        // устгагч функц
        ~employee(){
            cout << endl << "Ustgagch Function ajillaj Object ustlaa." << endl;
        };

};

// class - ийн гишүүдэд анхны утга оноох функц.
void employee::utga_onooh() {
    dugaar = 0;
    strcpy(ner, "");                               // мөн dugaar[0]='\0'; аргаар хүснэгтэд 0 утгыг оноож болно.
    strcpy(alban_tushaal, "");                     // мөн alban_tushaal[0]='\0'; аргаар хүснэгтэд 0 утгыг оноож болно.
    ajillasan_tsag=0;
}

// хэрэглэгчээс буюу гараас утга авах функц.
// тус бүрт нь гараас утга оноож авна.
void employee::garaas_utga_avah() {

    cout << "Ajiltanii dugaar, ner, alban tushaal, ajillasan tsagiig oruulna uu."<<"\n";    
    cin >> dugaar >> ner >> alban_tushaal >> ajillasan_tsag;

    /*
    cout << "Ajiltanii dugaariig oruulna uu: "<<endl;
    cin >> dugaar;
    cout << "Ajiltanii neriig oruulna uu: "<<endl;
    cin >> ner;
    cout << "Ajiltanii alban tushaaliig oruulna uu: "<<endl;
    cin >> alban_tushaal;
    cout << "Ajiltanii ajillasan tsagiig oruulna uu: "<<endl;
    cin >> ajillasan_tsag;
    */
}

// боловсруулсан мэдээлэл буюу цалин, нэр зэргийг дэлгэцэнд хэвлэж харуулах функц.
void employee::delgetsend_hevleh() {
    cout << "dugaar: " << dugaar << endl;
    cout << "ner: " << ner << endl;
    cout << "alban tushaal: " << alban_tushaal << endl;
    cout << "ajillasan tsag: " << ajillasan_tsag << endl;
    // цалин бодохын тулд нөхцөл шалгах бөгөөд өөр нэгэн функцийг дуудан ашиглана.
    cout << "tsalin: " << tsalin() << endl;
}

// нөхцөлөөс хамааруулан цалин бодох функц.
float employee::tsalin() {
    float SUM = 0;
    float TSALIN_ZAHIRAL = 0;
    float NEMELT_TSAG;
    int NEMELT_TSAG_AJILLASAN_ESEH;  

    // илүү цаг ажилласан эсэхийг шалгана.
    cout << "iluu tsag ajillasan uu: (1: tiim, 0: ugui) " << endl;
    cin >> NEMELT_TSAG_AJILLASAN_ESEH;

    // хэрэв нэмэлт цаг ажилласан бол ...
    if(NEMELT_TSAG_AJILLASAN_ESEH) {
        cout << "nemelteer heden tsag ajillasan be: (24 дотор байна) " << endl;
        cin >> NEMELT_TSAG;
        // нэмэлт цалин нөхцөлөөр шалгах 
        if(NEMELT_TSAG != 0 && NEMELT_TSAG <=24){
            ajillasan_tsag += NEMELT_TSAG;
        } else {
            cout << "nemelteer oruulsan tsag buruu buyu nemelt tsag baihgui bn." << endl;
        }
    }

    // захирал гэх албан тушаалтай эсэхийг шалгаад
    if (strcmp(alban_tushaal, "zahiral") == 0) {
        TSALIN_ZAHIRAL = tsalin_zahiral();
        /*
        cout << TSALIN_ZAHIRAL << " zahirliin tsalin " << "+" <<endl;
        */
    }

    // өмнө нь define preprocessor - оор тодорхойлсон цалинг ашиглана. // захирал бол нэмэгдүүлнэ.
    SUM = ajillasan_tsag * tsalin_defined + TSALIN_ZAHIRAL;
    cout << endl << "niit tsalin: ";
    return SUM;
}

// захирал гэх албан тушаалтай бол гэсэн нөхцөлөөр энэхүү функц дуудагдана. // тусд нь тодорхойлсон.
float employee::tsalin_zahiral() {
    // өмнө нь тодорхойлсон цалингаар ажилласан цагийг үржүүлэн бодож буцаана.
    return ajillasan_tsag * zahiral_tsalin_defined;
}

int main() {
    int max=0;
    cout << "Heden ajiltanii tsalin bodoh ve? " << endl;
    cin >> number;
    // employee class - аас emp гэх объектыг үүсгэнэ.
    
    /*employee emp;*/

    // employee class - аас emplo гэх хүснэгт үүсгэнэ.
    employee emplo[number];
    
    // үүсгэсэн объектийн гишүүдээр дамжуулан функцуудыг дуудна.
    /*
    emp.garaas_utga_avah();
    emp.delgetsend_hevleh();
    */
    // давталтаар number хүргэх бөгөөд нийт хэдэн объект үүсгэхийг тодорхойлон утгыг гараас авна.
    for(int i=0;i<number;i++){
        emplo[i].garaas_utga_avah();
    }
    // мөн number хүртэл давтан объектуудыг дэлгэцэнд хэвлэнэ.
    for(int i=0;i<number;i++){
        emplo[i].delgetsend_hevleh();
    }
    // хамгийн сүүлд объектууд ашиглагдаж дууссанаар үүссэн объектуудийг delete функцээр усгана.
}