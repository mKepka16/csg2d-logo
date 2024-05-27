#include "functions.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "numbers"
#include "operation.h"
#include "complex_shape.h"

sf::Vector2f rotate(const sf::Vector2f &v, float angle_rad)
{
	const float cs = std::cos(angle_rad);
	const float sn = std::sin(angle_rad);

	return { v.x*cs - v.y*sn, v.x*sn + v.y*cs };
}

void updateTexture(sf::Texture &t, const CSG2D::Shape &s, const sf::Color &foreground_color, const sf::Color &background_color)
{
	const auto tex_size = t.getSize();
	std::vector<sf::Uint8> tex_data(tex_size.x*tex_size.y*4u, 0u);
	const sf::Vector2f center = sf::Vector2f(tex_size)/2.f - sf::Vector2f(0.5f, 0.5f);
    for(std::size_t py = 0u; py < tex_size.y; ++py)
    {
	    for(std::size_t px = 0u; px < tex_size.x; ++px)
	    {
	        auto pos = sf::Vector2f(px, py) - center;
	        pos.y = -pos.y;
	        
	        const auto color = s.isIn(pos) ? foreground_color : background_color;

	        const std::size_t pi = py*tex_size.x + px;
	        const auto i = pi*4u;
	        tex_data[i] = color.r;
	        tex_data[i + 1u] = color.g;
	        tex_data[i + 2u] = color.b;
	        tex_data[i + 3u] = color.a;
	    }
    }
    t.update(tex_data.data());
}

std::shared_ptr<CSG2D::Shape> getM(const sf::Vector2f &mLetterCord) {
	auto mainRect = std::make_shared<CSG2D::Rectangle>(100.f, 100.f, mLetterCord, 0);
	auto bottomRect = std::make_shared<CSG2D::Rectangle>(50.f, 40.f, mLetterCord + sf::Vector2f(0, -30.f), 0);
	auto mainWithBottomRect = std::make_shared<CSG2D::ComplexShape>(mainRect, bottomRect, CSG2D::OPERATION::DIFFERENCE);
	auto topTrangle = std::make_shared<CSG2D::Rectangle>(30.f, 30.f, mLetterCord + sf::Vector2f(0, 50.f), degToRad(45));
	auto withoutTopTriangle = std::make_shared<CSG2D::ComplexShape>(mainWithBottomRect, topTrangle, CSG2D::OPERATION::DIFFERENCE);

	sf::Vector2f t1Pos(-12.5f, 0.f);
	auto r1 = std::make_shared<CSG2D::Rectangle>(25.f, 25.f, mLetterCord + t1Pos, 0);
	auto r2 = std::make_shared<CSG2D::Rectangle>(40.f, 40.f, mLetterCord + sf::Vector2f(10.f, 10.f) + t1Pos, degToRad(45));
	auto t1 = std::make_shared<CSG2D::ComplexShape>(r1, r2, CSG2D::OPERATION::DIFFERENCE);
	auto withoutT1 = std::make_shared<CSG2D::ComplexShape>(withoutTopTriangle, t1, CSG2D::OPERATION::DIFFERENCE);

	sf::Vector2f t2Pos(12.5f, 0.f);
	auto r12 = std::make_shared<CSG2D::Rectangle>(25.f, 25.f, mLetterCord + t2Pos, 0);
	auto r22 = std::make_shared<CSG2D::Rectangle>(40.f, 40.f, mLetterCord + sf::Vector2f(-10.f, 10.f) + t2Pos, degToRad(45));
	auto t2 = std::make_shared<CSG2D::ComplexShape>(r12, r22, CSG2D::OPERATION::DIFFERENCE);
	auto withoutT2 = std::make_shared<CSG2D::ComplexShape>(withoutT1, t2, CSG2D::OPERATION::DIFFERENCE);

	return withoutT2;
}

std::shared_ptr<CSG2D::Shape> getKHelper(const sf::Vector2f &kLetterCord) {
	auto mainRect = std::make_shared<CSG2D::Rectangle>(100.f, 100.f, kLetterCord, 0);
	auto rightRect = std::make_shared<CSG2D::Rectangle>(100.f, 100.f, kLetterCord + sf::Vector2f(70, 0), degToRad(45));
	auto withoutRight = std::make_shared<CSG2D::ComplexShape>(mainRect, rightRect, CSG2D::OPERATION::DIFFERENCE);

	return withoutRight;
}

std::shared_ptr<CSG2D::Shape> getK(const sf::Vector2f &kLetterCord) {
	auto mainHelper = getKHelper(kLetterCord);
	auto suppHelper = getKHelper(kLetterCord + sf::Vector2f(-40.f, 0));
	auto withoutSuppHelper = std::make_shared<CSG2D::ComplexShape>(mainHelper, suppHelper, CSG2D::OPERATION::DIFFERENCE);
	auto leftColRect = std::make_shared<CSG2D::Rectangle>(32.f, 100.f, kLetterCord + sf::Vector2f(-40, 0), 0);
	auto res = std::make_shared<CSG2D::ComplexShape>(withoutSuppHelper, leftColRect, CSG2D::OPERATION::UNION);
	return res;
}

std::shared_ptr<CSG2D::Shape> getHexagon(const sf::Vector2f &cord, float size) {
	auto rect1 = std::make_shared<CSG2D::Rectangle>(size, size * sqrt(3), cord, degToRad(30));
	auto rect2 = std::make_shared<CSG2D::Rectangle>(size, size * sqrt(3), cord, degToRad(90));
	auto rect3 = std::make_shared<CSG2D::Rectangle>(size, size * sqrt(3), cord, degToRad(150));
	auto res1 = std::make_shared<CSG2D::ComplexShape>(rect1, rect2, CSG2D::OPERATION::UNION);
	auto res2 = std::make_shared<CSG2D::ComplexShape>(res1, rect3, CSG2D::OPERATION::UNION);
	return res2;
}

std::shared_ptr<CSG2D::Shape> getSymmTrian(const sf::Vector2f &cord) {
	auto mainRect = std::make_shared<CSG2D::Rectangle>(80 * sqrt(3) / 2, 80, cord, 0);
	auto upperRect = std::make_shared<CSG2D::Rectangle>(80, 80, cord + sf::Vector2f(-20, 55), degToRad(30));
	auto rectWithoutTop = std::make_shared<CSG2D::ComplexShape>(mainRect, upperRect, CSG2D::OPERATION::DIFFERENCE);
	auto bottomRect = std::make_shared<CSG2D::Rectangle>(80, 80, cord + sf::Vector2f(-20, -55), degToRad(-30));
	auto res = std::make_shared<CSG2D::ComplexShape>(rectWithoutTop, bottomRect, CSG2D::OPERATION::DIFFERENCE);

	return res;
}

std::shared_ptr<CSG2D::Shape> getCross(const sf::Vector2f &cord, float size) {
	auto vertical = std::make_shared<CSG2D::Rectangle>(size, size * 3, cord, 0);
	auto horizontal = std::make_shared<CSG2D::Rectangle>(size, size * 3, cord, degToRad(90));
	auto res = std::make_shared<CSG2D::ComplexShape>(vertical, horizontal, CSG2D::OPERATION::UNION);
	return res;
}

std::shared_ptr<CSG2D::Shape> getCPPLogo(const sf::Vector2f &cord) {
	auto hexagon = getHexagon(cord, 80);
	auto outerCircle = std::make_shared<CSG2D::Circle>(50, cord);
	auto innerCircle = std::make_shared<CSG2D::Circle>(25, cord);
	auto circles = std::make_shared<CSG2D::ComplexShape>(outerCircle, innerCircle, CSG2D::OPERATION::DIFFERENCE);
	auto hexagonWithoutCircle = std::make_shared<CSG2D::ComplexShape>(hexagon, circles, CSG2D::OPERATION::DIFFERENCE);
	auto triangle = getSymmTrian(cord + sf::Vector2f(30, 0));
	auto withTrangle = std::make_shared<CSG2D::ComplexShape>(hexagonWithoutCircle, triangle, CSG2D::OPERATION::UNION);
	auto firstCross = getCross(cord + sf::Vector2f(38, 0), 5);
	auto withFirstCross = std::make_shared<CSG2D::ComplexShape>(withTrangle, firstCross, CSG2D::OPERATION::DIFFERENCE);
	auto secondCross = getCross(cord + sf::Vector2f(57, 0), 5);
	auto res = std::make_shared<CSG2D::ComplexShape>(withFirstCross, secondCross, CSG2D::OPERATION::DIFFERENCE);
	return res;
}

std::shared_ptr<CSG2D::Shape> createCSG2DScene()
{
	auto m = getM({ -70.f, 200.f });
	auto k = getK({ 70.f, 200.f });
	auto mAndk = std::make_shared<CSG2D::ComplexShape>(m, k, CSG2D::OPERATION::UNION);
	auto cppLogo = getCPPLogo({0, 0});

	auto res = std::make_shared<CSG2D::ComplexShape>(mAndk, cppLogo, CSG2D::OPERATION::UNION);

	return res;
}
