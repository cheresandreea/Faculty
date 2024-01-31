#include "ValidationException.h"

void PetValidator::validate(const Dog& dog)
{
    if (dog.getName().empty()) {
        throw ValidationException("Pet name cannot be empty.");
    }
    if (dog.getAge() < 0 || dog.getAge() > 20) {
        throw ValidationException("Invalid pet age.");
    }
    
    if (dog.getBreed().empty()) {
			throw ValidationException("Pet breed cannot be empty.");
		}
    if (dog.getPhotography().empty()) {
			throw ValidationException("Pet link cannot be empty.");
		}
}
