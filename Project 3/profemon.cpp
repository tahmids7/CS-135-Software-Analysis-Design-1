//Name: Tahmid Sahan
//Date: 5/10/23
//Instructor: Genaddiy Maryash
//Rec Instructor: Enxhi Osmanllari
//Assignment: Project 3

#include "profemon.hpp"
#include <iostream>
#include <string>

using namespace std;

Profemon::Profemon() {
  name = "Undefined";
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty) {
  this->name = name;
  this->maxHealth = max_health;
  this->specialty = specialty;
  this->reqExp = 50;
  this->currExp = 0;
  this->level = 0;
}

std::string Profemon::getName() {
  return Profemon::name;
}

Specialty Profemon::getSpecialty() {
  return specialty;
}

int Profemon::getLevel() {
  return level;
}

double Profemon::getMaxHealth() {
  return maxHealth;
}

void Profemon::setName(std::string name) {
  this->name = name;
}

void Profemon::levelUp(int exp) {
  
  currExp += exp;
  
  while (currExp >= reqExp) {
    
    level++;
    currExp -= reqExp;
    
    if (specialty == Specialty::ML) {
      reqExp += 10;
    } else if (specialty == Specialty::SOFTWARE) {
      reqExp += 15;
    } else if (specialty == Specialty::HARDWARE) {
      reqExp += 20;
    } else {
      break;
    }
      
  }
  
}


bool Profemon::learnSkill(int slot, Skill skill) {
  
  if (slot < 0 || slot > 2) {
    return false;
  }

  if(skill.getSpecialty() != specialty){
    return false;
  }
  
  skills[slot].setName(skill.getName());
  skills[slot].setDescription(skill.getDescription());
  skills[slot].setTotalUses(skill.getTotalUses());
  skills[slot].setSpecialty(skill.getSpecialty());
  
  return true;

}

void Profemon::printProfemon(bool print_skills) {

  std::string specialty_stringified;
  
  if (specialty == Specialty::ML) {
    specialty_stringified = "ML";
  } else if (specialty == Specialty::SOFTWARE) {
    specialty_stringified = "SOFTWARE";
  } else if (specialty == Specialty::HARDWARE) {
    specialty_stringified = "HARDWARE";
  } else {
    specialty_stringified = "Undefined";
  }
  
  std::cout << name << " [" << specialty_stringified << "]" 
  << " | lvl " << level 
  << " | exp " << currExp
  << "/" << reqExp 
  << " | hp " << maxHealth 
  << std::endl;
  
  if (print_skills) {
    for (int i = 0; i < 3; i++) {
      if (skills[i].getName() != "Undefined") {
        std::cout << "    " << skills[i].getName() << " [" << skills[i].getTotalUses() << "] : "
        << skills[i].getDescription() << std::endl;
      }
    }
  }
  
}
