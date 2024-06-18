
const { faker } = require('@faker-js/faker');

const generateCollars = () => {
    const numbers = [1, 2, 3, 4, 5];
    const generatedCollars = [];
    for (let id = 20; id < 40; id++) {
        const title = faker.commerce.productName();
        const description = faker.commerce.product();
        const material = faker.commerce.productMaterial();
        const price = faker.commerce.price();
        const stars = numbers[Math.floor(Math.random() * numbers.length)];

        generatedCollars.push({
            id,
            title,
            description,
            material,
            price,
            stars
        });
    }
    return generatedCollars;
}


module.exports = generateCollars;