#include "raylib.h"


void Draw3DButton(Rectangle rect, Color color, int borderRadius, int depth) {
    // Draw main button
    DrawRectangleRounded(rect, (float)borderRadius / rect.width, 10, color);

    // Add top shading for 3D effect
    Rectangle topShade = { rect.x, rect.y, rect.width, static_cast<float>(depth) };
    DrawRectangleRoundedLines(topShade, (float)borderRadius / rect.width, 10, depth, Fade(BLACK, 0.3f));

    // Add bottom shading for 3D effect
    Rectangle bottomShade = { rect.x, rect.y + rect.height - depth, rect.width, static_cast<float>(depth) };
    DrawRectangleRoundedLines(bottomShade, (float)borderRadius / rect.width, 10, depth, Fade(WHITE, 0.3f));
}

void DrawButtonWithBorder(Rectangle rect, Color color, int borderRadius, int borderWidth) {
    // Draw main button
    DrawRectangleRounded(rect, (float)borderRadius / rect.width, 10, color);

    // Add white border
    Rectangle borderRect = { rect.x - borderWidth, rect.y - borderWidth, rect.width + 2 * borderWidth, rect.height + 2 * borderWidth };
    DrawRectangleRoundedLines(borderRect, (float)borderRadius / borderRect.width, 10, borderWidth, WHITE);
}
