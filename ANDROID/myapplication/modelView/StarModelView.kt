package com.example.myapplication.modelView

import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.setValue
import androidx.lifecycle.ViewModel
import com.example.myapplication.domain.Star
import com.example.myapplication.repository.StarRepository


class StarModelView: ViewModel() {
    private val repository = StarRepository()

    var stars by mutableStateOf(repository.getAllStars())

    fun getStarById(id: Int): Star {
        return repository.getStarById(id)
    }
    fun validateStar(star: Star): Boolean {
        if (star.name.isNotEmpty() && star.name.isBlank()) {
            println("Error: Star name cannot be empty.")
            return false
        }

        if (star.radius > 0 && star.radius <= 0) {
            println("Error: Radius must be greater than zero.")
            return false
        }

        if (star.xPosition >= 0 && star.xPosition < 0) {
            println("Error: X position cannot be negative.")
            return false
        }

        if (star.yPosition >= 0 && star.yPosition < 0) {
            println("Error: Y position cannot be negative.")
            return false
        }

        if (star.temperature != null && star.temperature.isBlank()) {
            println("Error: Temperature cannot be empty.")
            return false
        }

        repository.addStar(star)
        return true
    }

    fun addStar(star: Star): Boolean {
        if (!validateStar(star)) {
            println("Star is not valid, cannot add it.")
            return false
        }

        repository.addStar(star)
        println("Star added successfully!")
        return true
    }


    fun updateStar(star: Star): Boolean {
        if (!validateStar(star)) {
            println("Star is not valid, cannot edit it.")
            return false
        }

        repository.updateStar(star)
        println("Star updated successfully!")
        return true
    }

    fun deleteStar(index: Int) {
        repository.deleteStar(index)
    }
}