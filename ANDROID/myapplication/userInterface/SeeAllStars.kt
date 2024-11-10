package com.example.myapplication.userInterface

import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.Button
import androidx.compose.material3.ButtonDefaults
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
import com.example.myapplication.ui.components.StarItem
import com.example.myapplication.ui.components.StarItemDetails

@Composable
fun SeeAllStars(starList: List<Star>, starModelView: StarModelView, navController: NavController, modifier: Modifier = Modifier) {
    var selectedStar by remember { mutableStateOf<Star?>(null) }

    Box(modifier.fillMaxSize()) {
        val image = painterResource(R.drawable.star)
        Image(
            painter = image,
            contentDescription = null,
            contentScale = ContentScale.Crop,
            alpha = 0.5F
        )
        Column(
            modifier = Modifier.fillMaxSize(),
            horizontalAlignment = Alignment.Start,
            verticalArrangement = Arrangement.Center ) {
            // "Add New Star" Button
            Row{
                Text(
                    text = "Stars",
                    fontSize = 25.sp,
                    lineHeight = 10.sp,
                    textAlign = TextAlign.Center,
                    modifier = Modifier.padding(25.dp),
                    fontWeight = FontWeight.Bold,
                )

                Button(
                    onClick = {
                        navController.navigate("AddStarScreen")
                    },
                    modifier = Modifier
                        .padding(16.dp),

                    //colors = ButtonDefaults.buttonColors(containerColor = androidx.compose.ui.graphics.Color.DarkGray)
                ) {
                    Text("Add Star") // Text is white on red button
                }

            }

            LazyColumn(
                modifier = Modifier.fillMaxSize()
            ) {
                items(starList) { star ->
                    StarItem(star = star,
                        onClick = {
                            // Navigate to StarDetailsScreen with the selected star ID
                            navController.navigate("starDetails/${star.id}")
                        }
                    )

                    Row {
                        Button(
                            onClick = {
                                starModelView.deleteStar(star.id)
                            },
                            modifier = Modifier
                                .padding(16.dp),

                            colors = ButtonDefaults.buttonColors(containerColor = androidx.compose.ui.graphics.Color.Red)
                        ) {
                            Text("Delete", color = androidx.compose.ui.graphics.Color.White) // Text is white on red button
                        }

                        Button(
                            onClick = {
                                navController.navigate("EditStar/${star.id}")
                            },
                            modifier = Modifier
                                .padding(16.dp),

                            colors = ButtonDefaults.buttonColors(containerColor = androidx.compose.ui.graphics.Color.Green)
                        ) {
                            Text("Edit", color = androidx.compose.ui.graphics.Color.White) // Text is white on green button
                        }

                    }


                }
            }


        }
        selectedStar?.let {
            StarItemDetails(star = it)
        }

    }
}