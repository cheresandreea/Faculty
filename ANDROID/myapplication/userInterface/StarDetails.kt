package com.example.myapplication.userInterface

import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
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
import com.example.myapplication.modelView.StarModelView
import com.example.myapplication.ui.components.StarItemDetails

@Composable
fun StarDetails(starId: Int, navController: NavController, starModelView: StarModelView, modifier: Modifier = Modifier) {
    val star = starModelView.getStarById(starId)

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
            verticalArrangement = Arrangement.Top ) {
            Text(
                text = "Stars",
                fontSize = 25.sp,
                lineHeight = 10.sp,
                textAlign = TextAlign.Start,
                modifier = Modifier.padding(16.dp),
                fontWeight = FontWeight.Bold,

                )
            StarItemDetails(star = star)
            Button(
                onClick = { navController.navigate("seeAllStars")},
            ) { }
        }
    }



}