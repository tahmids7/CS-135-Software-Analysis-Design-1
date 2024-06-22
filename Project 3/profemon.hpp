//Name: Tahmid Sahan
//Date: 5/10/23
//Instructor: Genaddiy Maryash
//Rec Instructor: Enxhi Osmanllari
//Assignment: Project 3

#ifndef PROFEMON_HPP
#define PROFEMON_HPP

#include <string>
#include "skill.hpp"

enum Specialty {ML, SOFTWARE, HARDWARE};

class Profemon {
  private:
    std::string name; // The name of the Profémon
    int level; // The name of the Profémon
    double maxHealth; // The maximum health level
    int reqExp; // The required experience to level up
    int currExp; // The current experience
    Specialty specialty; // The specialty of the profemon
    Skill skills[3]; // A 'Skill' array of size 3 containing skills learned by the profémon

  public:
    Profemon();
    Profemon(std::string name, double max_health, Specialty specialty);
    std::string getName();
    Specialty getSpecialty();
    int getLevel();
    double getMaxHealth();
    void setName(std::string name);
    void levelUp(int exp);
    bool learnSkill(int slot, Skill skill);  
    void printProfemon(bool print_skills);
};

#endif
