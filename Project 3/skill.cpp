//Name: Tahmid Sahan
//Date: 5/10/23
//Instructor: Genaddiy Maryash
//Rec Instructor: Enxhi Osmanllari
//Assignment: Project 3

#include "skill.hpp" 

Skill::Skill() {
  name = "Undefined";
  description = "Undefined";
  total = -1;
  specialty = -1;
}

Skill::Skill(std::string name, std::string description, int specialty, int uses) {
  this->name = name;
  this->description = description;
  this->specialty = specialty;
  this->total = uses;
}

std::string Skill::getName() {
  return name;
}

std::string Skill::getDescription() {
  return description;
}

int Skill::getTotalUses() {
  return total;
}

int Skill::getSpecialty() {
  return specialty;
}

void Skill::setName(std::string name) {
  this->name = name;
}

void Skill::setDescription(std::string description) {
  this->description = description;
}

void Skill::setTotalUses(int uses) {
  total = uses;
}

bool Skill::setSpecialty(int specialty) {
  if (specialty == 0 || specialty == 1 || specialty == 2) {
    this->specialty = specialty;
    return true;
  } else {
    return false;
  }
}
