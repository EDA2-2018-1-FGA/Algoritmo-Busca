#include "services.h"

const std::string name_list[71] = {"André","Adriana","Adriano","Alisson","Bruno","Bruna",
                                   "Caio","Catarina","Camila","Daniela","Danilo","Elton",
                                   "Emerson","Emily","Fabiana","Fabiano","Fabiola","Felipe",
                                   "Fagner","Gabriel","Gabriela","Helen","Isabel","Isabele",
                                   "Isabela","Igor","Iago","João","Jaqueline","Jorge","José",
                                   "Katarine","Kleber","Karine","Larissa","Luciana","Luciano",
                                   "Leticia","Lucas","Maria","Matheus","Marcos","Marcelo","Marcela",
                                   "Maicon","Michael","Monique","Nathalia","Nicolas","Patricia",
                                   "Patrick","Pamela","Raissa","Rodinei","Roberto","Rodrigo","Tais",
                                   "Tamara","Tulio","Vitor","Vinicius","Valter","Vitoria","Vanessa",
                                   "Wesley","Walter","Wendel","William","Weber","Yan","Zilma"};
const std::string surname_list[81] = { "Alves","Abreu","Almeida","Amorim","Araujo","Brito","Borges",
                                       "Braga","Bernardes","Barros","Campos","Carvalho","Correa","Cabral",
                                       "Cardoso","Costa","Dantas","da Silva","de Abreu","de Souza","Esteves",
                                       "Ferreira","Faria","Fonsceca","Fagundes","Guerra","Gomes","Garcia",
                                       "Graça","Jacinto","Klein","Lourenço","Lima","Lopes","Leite","Lacerda",
                                       "Lago","Machado","Marinho","Mesquita","Magalhães","Muniz","Mendonça",
                                       "Meira","Meireles","Nogueira","Noronha","Novaes","Neves","Neto","Nunes",
                                       "Oliveira","Pereira","Pacheco","Paes","Paiva","Passos","Pessoa","Pires",
                                       "Pinheiro","Prado","Pontes","Porto","Rios","Rosa","Rossi","Rabelo","Ramos",
                                       "Rodrigues","Sales","Santos","Silva","Souza","Siqueira","Toledo","Viana",
                                       "Vieira","Vaz","Vasconcelos","Xavier","Zanetti"};


People*
Services::generate(const int length){
  People* peoples = new People[length];
  for(int i = 0; i < length; i++){
    peoples[i].set_name(Services::generate_name());
    peoples[i].set_height(Services::generate_height());
    peoples[i].set_weight(Services::generate_weight());
  }
  return peoples;
}

int
Services::generate_height(){
  const int minimum_height = 120;
  const int range_height = 100;
  const int height = rand() % range_height + minimum_height;
  return height;
}

double
Services::generate_weight(){
  const double minimum_weight = 40.0;
  const double maximum_weight = 120.0;
  const double weight = (maximum_weight - minimum_weight) * ( (double)rand() / (double)RAND_MAX ) + minimum_weight;
  return weight;
}

std::string
Services::generate_name(){
  const int name_random_index = rand() % 71;
  const int surname_random_index = rand() % 81;
  const std::string name = name_list[name_random_index] + " " + surname_list[surname_random_index];
  return name;
}

void
Services::print_peoples(People peoples[], const int length){
  std::cout << std::setw(22) << "Name" << " | " << std::setw(5) <<"Weight(Kg)" << " | " << std::setw(5) << "Height(cm)" << std::endl;
  for(int i = 0; i < length; i++){
      std::cout << std::setw(21) << peoples[i].get_name() << "  | ";
      std::cout << std::setw(10) << peoples[i].get_weight() << " | ";
      std::cout << std::setw(5) << peoples[i].get_height() << std::endl;
  }
}

void
Services::print_peoples(People peoples[], const int length, const int* idx){
  std::cout << "  ID   |"<< std::setw(22) << "Name" << " | " << std::setw(5) <<"Weight(Kg)" << " | " << std::setw(5) << "Height(cm)" << std::endl;
  for(int i = 0; i < length; i++){
      std::cout << std::setw(5) << i << "  | ";
      std::cout << std::setw(21) << peoples[idx[i]].get_name() << "  | ";
      std::cout << std::setw(10) << peoples[idx[i]].get_weight() << " | ";
      std::cout << std::setw(5) << peoples[idx[i]].get_height() << std::endl;
  }
}

void
Services::print_peoples_g(People peoples[], const int length, const int* ordened, const int* idx){

  for(int i = 0, j = 0; i < length; i++){

    if(idx[j] == i){
      std::cout << "Letra " << (char)('A' + j) << ": " << idx[j] << std::endl;
      j++;
    }else if(idx[j] == INT_MAX){
      std::cout << "Letra " << (char)('A' + j) << ": " << idx[j] << std::endl;
      j++;
      continue;
    }

    std::cout << std::setw(5) << i << "  | ";
    std::cout << std::setw(21) << peoples[ordened[i]].get_name() << "  | ";
    std::cout << std::setw(10) << peoples[ordened[i]].get_weight() << " | ";
    std::cout << std::setw(5) <<  peoples[ordened[i]].get_height() << std::endl;
  }
}
