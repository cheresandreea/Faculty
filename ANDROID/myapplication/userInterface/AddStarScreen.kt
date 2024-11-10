package com.example.myapplication.userInterface

import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Button
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
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
import com.example.myapplication.ui.components.StarItemDetails
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.TextField
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue

@Composable
fun AddStar(navController: NavController, starModelView: StarModelView, modifier: Modifier = Modifier) {

    var starName by remember { mutableStateOf("") }
    var radius by remember { mutableStateOf("") }
    var xPosition by remember { mutableStateOf("") }
    var yPosition by remember { mutableStateOf("") }
    var temperature by remember { mutableStateOf("") }
    var galaxy by remember { mutableStateOf("") }
    var constellation by remember { mutableStateOf("") }
    var description by remember { mutableStateOf("") }
    var photo by remember { mutableStateOf("") }

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
                text = "Add a Star",
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


            OutlinedTextField(
                value = temperature,
                onValueChange = { temperature = it },
                label = { Text("Temperature") },
                modifier = Modifier.fillMaxWidth().padding(vertical = 4.dp)
            )


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

            // Add Star Button
            Button(
                onClick = {
                    val newStarId = (starModelView.stars.size + 1)
                    starModelView.addStar(
                        Star(
                            id = newStarId,
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
                Text("Add Star")
            }
        }
    }
}
