package com.example.myapplication.userInterface

import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Button
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.navigation.NavController
import com.example.myapplication.R
import com.example.myapplication.domain.Star
import com.example.myapplication.modelView.StarModelView

@Composable
fun EditStar(
    starId: Int,
    navController: NavController,
    starModelView: StarModelView,
    modifier: Modifier = Modifier
) {
    // Find the star by ID
    val star = starModelView.stars.firstOrNull { it.id == starId }

    // If the star is found, populate the form with its details
    if (star != null) {
        var starName by remember { mutableStateOf(star.name) }
        var radius by remember { mutableStateOf(star.radius.toString()) }
        var xPosition by remember { mutableStateOf(star.xPosition.toString()) }
        var yPosition by remember { mutableStateOf(star.yPosition.toString()) }
        var temperature by remember { mutableStateOf(star.temperature) }
        var galaxy by remember { mutableStateOf(star.galaxy) }
        var constellation by remember { mutableStateOf(star.constellation) }
        var description by remember { mutableStateOf(star.description) }
        var photo by remember { mutableStateOf(star.photo) }

        Box(modifier.fillMaxSize()) {
            val image = painterResource(R.drawable.star)
            Image(
                painter = image,
                contentDescription = null,
                contentScale = ContentScale.Crop,
                alpha = 0.5F
            )

            Column(
                modifier = Modifier
                    .fillMaxSize()
                    .padding(16.dp),
                horizontalAlignment = Alignment.Start,
                verticalArrangement = Arrangement.Top
            ) {
                Text(
                    text = "Stars",
                    fontSize = 25.sp,
                    lineHeight = 10.sp,
                    textAlign = TextAlign.Start,
                    fontWeight = FontWeight.Bold,
                )

                Text(
                    text = "Edit Star",
                    fontSize = 18.sp,
                    lineHeight = 10.sp,
                    textAlign = TextAlign.Start,
                    fontWeight = FontWeight.Bold,
                    modifier = Modifier.padding(vertical = 8.dp)
                )

                OutlinedTextField(
                    value = starName,
                    onValueChange = { starName = it },
                    label = { Text("Star Name") },
                    modifier = Modifier.fillMaxWidth().padding(vertical = 4.dp)
                )

                OutlinedTextField(
                    value = radius,
                    onValueChange = { radius = it },
                    label = { Text("Radius") },
                    modifier = Modifier.fillMaxWidth().padding(vertical = 4.dp)
                )

                OutlinedTextField(
                    value = xPosition,
                    onValueChange = { xPosition = it },
                    label = { Text("X Position") },
                    modifier = Modifier.fillMaxWidth().padding(vertical = 4.dp)
                )


                OutlinedTextField(
                    value = yPosition,
                    onValueChange = { yPosition = it },
                    label = { Text("Y Position") },
                    modifier = Modifier.fillMaxWidth().padding(vertical = 4.dp)
                )

                temperature?.let {
                    OutlinedTextField(
                        value = it,
                        onValueChange = { temperature = it },
                        label = { Text("Temperature") },
                        modifier = Modifier.fillMaxWidth().padding(vertical = 4.dp)
                    )
                }

                OutlinedTextField(
                    value = galaxy,
                    onValueChange = { galaxy = it },
                    label = { Text("Galaxy") },
                    modifier = Modifier.fillMaxWidth().padding(vertical = 4.dp)
                )

                OutlinedTextField(
                    value = constellation,
                    onValueChange = { constellation = it },
                    label = { Text("Constellation") },
                    modifier = Modifier.fillMaxWidth().padding(vertical = 4.dp)
                )

                OutlinedTextField(
                    value = description,
                    onValueChange = { description = it },
                    label = { Text("Description") },
                    modifier = Modifier.fillMaxWidth().padding(vertical = 4.dp)
                )


                Button(
                    onClick = {
                        starModelView.updateStar(
                            Star(
                                id = star.id,  // Retain the same star ID
                                name = starName,
                                radius = radius.toFloatOrNull() ?: 0f,
                                xPosition = xPosition.toFloatOrNull() ?: 0f,
                                yPosition = yPosition.toFloatOrNull() ?: 0f,
                                temperature = temperature,
                                galaxy = galaxy,
                                constellation = constellation,
                                description = description,
                                photo = photo
                            )
                        )
                        navController.navigate("SeeAllStars")
                    },
                    modifier = Modifier.padding(vertical = 16.dp)
                ) {
                    Text("Save Changes")
                }
            }
        }
    } else {
        Text("Star not found")
    }
}