package com.example.myapplication.repository

import androidx.compose.runtime.mutableStateListOf
import com.example.myapplication.domain.Star

class StarRepository {
    private val starList = mutableStateListOf(
        Star(
            id = 1,
            name = "Sirius",
            radius = 1.711f,
            xPosition = 0.0f,
            yPosition = 0.0f,
            temperature = "9940 K",
            galaxy = "Milky Way",
            constellation = "Canis Major",
            description = "Brightest star in Earth's night sky.",
            photo = null
        ),
        Star(
            id = 2,
            name = "Betelgeuse",
            radius = 887.0f,
            xPosition = 0.0f,
            yPosition = 0.0f,
            temperature = "3500 K",
            galaxy = "Milky Way",
            constellation = "Orion",
            description = "A red supergiant star.",
            photo = null
        ),
        // New Stars added below
        Star(
            id = 3,
            name = "Alpha Centauri",
            radius = 1.5f,
            xPosition = 1.34f,
            yPosition = 1.02f,
            temperature = "5790 K",
            galaxy = "Milky Way",
            constellation = "Centaurus",
            description = "The closest star system to Earth.",
            photo = null
        ),
        Star(
            id = 4,
            name = "Proxima Centauri",
            radius = 0.14f,
            xPosition = 1.3f,
            yPosition = 2.0f,
            temperature = "3042 K",
            galaxy = "Milky Way",
            constellation = "Centaurus",
            description = "The closest known star to the Sun.",
            photo = null
        ),
        Star(
            id = 5,
            name = "Rigel",
            radius = 78.0f,
            xPosition = 1.45f,
            yPosition = 3.1f,
            temperature = "12000 K",
            galaxy = "Milky Way",
            constellation = "Orion",
            description = "A blue supergiant star.",
            photo = null
        ),
        Star(
            id = 6,
            name = "Arcturus",
            radius = 25.0f,
            xPosition = 1.2f,
            yPosition = 4.5f,
            temperature = "4290 K",
            galaxy = "Milky Way",
            constellation = "Boötes",
            description = "A red giant star.",
            photo = null
        ),
        Star(
            id = 7,
            name = "Aldebaran",
            radius = 44.0f,
            xPosition = 2.3f,
            yPosition = 3.8f,
            temperature = "4290 K",
            galaxy = "Milky Way",
            constellation = "Taurus",
            description = "The eye of the bull, a red giant star.",
            photo = null
        ),
        Star(
            id = 8,
            name = "Vega",
            radius = 2.1f,
            xPosition = 0.9f,
            yPosition = 5.4f,
            temperature = "9600 K",
            galaxy = "Milky Way",
            constellation = "Lyra",
            description = "One of the brightest stars in the night sky.",
            photo = null
        ),
        Star(
            id = 9,
            name = "Capella",
            radius = 10.0f,
            xPosition = 4.1f,
            yPosition = 2.2f,
            temperature = "5700 K",
            galaxy = "Milky Way",
            constellation = "Auriga",
            description = "A binary star system, the sixth-brightest star in the sky.",
            photo = null
        ),
        Star(
            id = 10,
            name = "Antares",
            radius = 883.0f,
            xPosition = 3.0f,
            yPosition = 6.1f,
            temperature = "3500 K",
            galaxy = "Milky Way",
            constellation = "Scorpius",
            description = "A red supergiant star.",
            photo = null
        ),
        Star(
            id = 11,
            name = "Spica",
            radius = 7.0f,
            xPosition = 5.1f,
            yPosition = 3.0f,
            temperature = "22200 K",
            galaxy = "Milky Way",
            constellation = "Virgo",
            description = "A binary star system, one of the hottest stars visible to the naked eye.",
            photo = null
        ),
        Star(
            id = 12,
            name = "Regulus",
            radius = 3.4f,
            xPosition = 0.5f,
            yPosition = 7.2f,
            temperature = "13700 K",
            galaxy = "Milky Way",
            constellation = "Leo",
            description = "A blue giant star and the brightest in the constellation Leo.",
            photo = null
        ),
        Star(
            id = 13,
            name = "Pollux",
            radius = 8.0f,
            xPosition = 1.0f,
            yPosition = 8.0f,
            temperature = "4600 K",
            galaxy = "Milky Way",
            constellation = "Gemini",
            description = "The brightest star in the constellation Gemini.",
            photo = null
        ),
        Star(
            id = 14,
            name = "Altair",
            radius = 1.8f,
            xPosition = 2.0f,
            yPosition = 9.0f,
            temperature = "7500 K",
            galaxy = "Milky Way",
            constellation = "Aquila",
            description = "A bright, white star in the constellation Aquila.",
            photo = null
        ),
        Star(
            id = 15,
            name = "Deneb",
            radius = 203.0f,
            xPosition = 3.5f,
            yPosition = 10.0f,
            temperature = "8500 K",
            galaxy = "Milky Way",
            constellation = "Cygnus",
            description = "A blue supergiant star, one of the most distant stars visible to the naked eye.",
            photo = null
        ),
        Star(
            id = 16,
            name = "Sadr",
            radius = 3.0f,
            xPosition = 4.0f,
            yPosition = 11.0f,
            temperature = "9700 K",
            galaxy = "Milky Way",
            constellation = "Cygnus",
            description = "A yellow supergiant star.",
            photo = null
        ),
        Star(
            id = 17,
            name = "Aldebaran",
            radius = 44.0f,
            xPosition = 1.0f,
            yPosition = 12.0f,
            temperature = "4290 K",
            galaxy = "Milky Way",
            constellation = "Taurus",
            description = "The eye of the bull, a red giant star.",
            photo = null
        )
    )

    fun getStarById(starId: Int): Star {
        return starList.find { it.id == starId } ?: Star(0, "", 0.0f, 0.0f, 0.0f, "", "", "", "", "")
    }

    fun addStar(star: Star) {
        starList.add(star)
    }

    fun getAllStars(): List<Star> {
        return starList
    }

    fun updateStar(star: Star) {
        val index = starList.indexOfFirst { it.id == star.id }

        if (index != -1) {
            starList[index] = star
        }
    }

    fun deleteStar(starId: Int) {
        starList.removeAll { it.id == starId }
    }

    // Sync any offline changes to the server
    fun refreshDatabase() { /* Sync offline changes to server */ }
}
