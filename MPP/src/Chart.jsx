import React from 'react';
import Paper from '@mui/material/Paper';
import {
    Chart,
    PieSeries,
    Title,
    Legend,
    Tooltip,
} from '@devexpress/dx-react-chart-material-ui';
import { useSelector } from 'react-redux';

export default function PieChart() {
    const collars = useSelector((state) => state.collars.dataCollars);

    if (!collars || collars.length === 0) {
        return <div>No collar data available</div>;
    }

    const chartData = collars.reduce((acc, collar) => {
        const existingMaterialIndex = acc.findIndex(
            (item) => item.material === collar.material
        );
        if (existingMaterialIndex !== -1) {
            acc[existingMaterialIndex].number++;
        } else {
            acc.push({ material: collar.material, number: 1 });
        }
        return acc;
    }, []);

    // Sort chart data by the number of collars for each material
    chartData.sort((a, b) => a.number - b.number);
    console.log(chartData);

    return (
        <Paper style={{ width: '100%', height: '700px' }}>
            <Chart style={{ width: '40%' }} data={chartData}>
                <PieSeries valueField="number" argumentField="material" />
                <Title text="Number of collars for each material" />
                <Legend style={{ width: '30%' }}/>
                <Tooltip />
            </Chart>
        </Paper>
    );
}
