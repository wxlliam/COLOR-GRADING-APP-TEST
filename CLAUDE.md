# CLAUDE.md - AI Assistant Guide for COLOR-GRADING-APP-TEST

**Last Updated:** 2025-11-17
**Repository:** wxlliam/COLOR-GRADING-APP-TEST
**Current Branch:** claude/claude-md-mi2il4ps3guk4fs9-013bqBTitj4Qw4HZEmfFkEn2

---

## Table of Contents

1. [Repository Overview](#repository-overview)
2. [Current State](#current-state)
3. [Recommended Project Structure](#recommended-project-structure)
4. [Technology Stack Recommendations](#technology-stack-recommendations)
5. [Development Workflows](#development-workflows)
6. [Coding Conventions](#coding-conventions)
7. [Git Workflow](#git-workflow)
8. [Testing Guidelines](#testing-guidelines)
9. [AI Assistant Guidelines](#ai-assistant-guidelines)
10. [Common Tasks](#common-tasks)

---

## Repository Overview

### Purpose
This repository is intended for a color grading application - a tool for adjusting and enhancing the color properties of images or videos. Color grading is commonly used in photography, videography, and content creation for:
- Adjusting brightness, contrast, and saturation
- Applying color filters and LUTs (Look-Up Tables)
- Creating consistent color palettes across media
- Correcting white balance and exposure
- Applying creative color effects

### Project Type
Fresh/Empty Repository - Ready for initial development

---

## Current State

### Repository Status ⚠️
**As of 2025-11-17:** This is a **fresh, empty repository** with minimal scaffolding.

**What Exists:**
- `.git/` - Git repository initialized
- `README.md` - Minimal project title only
- `CLAUDE.md` - This documentation file

**What's Missing:**
- ❌ No application code
- ❌ No technology stack defined
- ❌ No configuration files
- ❌ No test suite
- ❌ No build/deployment setup
- ❌ No .gitignore file
- ❌ No dependency management

**Git Information:**
- **Initial Commit:** 230ab54 (November 16, 2025)
- **Author:** wxlliam
- **Remote:** http://local_proxy@127.0.0.1:16264/git/wxlliam/COLOR-GRADING-APP-TEST

---

## Recommended Project Structure

Given this is a color grading application, here's a recommended structure based on common tech stacks:

### Option 1: Web Application (React + Python Backend)

```
COLOR-GRADING-APP-TEST/
├── frontend/
│   ├── src/
│   │   ├── components/      # React components
│   │   │   ├── ColorPicker/
│   │   │   ├── ImageCanvas/
│   │   │   ├── LUTLoader/
│   │   │   ├── HistogramView/
│   │   │   └── Controls/
│   │   ├── hooks/           # Custom React hooks
│   │   ├── utils/           # Helper functions
│   │   ├── services/        # API clients
│   │   ├── styles/          # CSS/styling
│   │   ├── App.tsx          # Main app component
│   │   └── index.tsx        # Entry point
│   ├── public/
│   ├── package.json
│   ├── tsconfig.json
│   └── vite.config.ts       # or webpack.config.js
├── backend/
│   ├── app/
│   │   ├── api/             # API routes
│   │   ├── core/            # Core config
│   │   ├── models/          # Data models
│   │   ├── services/        # Business logic
│   │   │   ├── color_correction.py
│   │   │   ├── lut_processor.py
│   │   │   └── image_processor.py
│   │   └── utils/
│   ├── tests/
│   ├── requirements.txt
│   ├── pyproject.toml
│   └── main.py
├── shared/
│   └── types/               # Shared type definitions
├── tests/
│   ├── e2e/                 # End-to-end tests
│   └── integration/
├── docs/
│   ├── API.md
│   ├── ARCHITECTURE.md
│   └── DEVELOPMENT.md
├── docker/
│   ├── Dockerfile.frontend
│   ├── Dockerfile.backend
│   └── docker-compose.yml
├── .github/
│   └── workflows/
│       ├── ci.yml
│       └── deploy.yml
├── .gitignore
├── README.md
├── CLAUDE.md
├── LICENSE
└── CONTRIBUTING.md
```

### Option 2: Desktop Application (Electron + TypeScript)

```
COLOR-GRADING-APP-TEST/
├── src/
│   ├── main/                # Electron main process
│   │   ├── index.ts
│   │   └── ipc/             # IPC handlers
│   ├── renderer/            # Renderer process (UI)
│   │   ├── components/
│   │   ├── pages/
│   │   └── index.tsx
│   ├── shared/
│   │   ├── types/
│   │   └── constants/
│   └── utils/
│       ├── colorProcessing.ts
│       ├── lutParser.ts
│       └── imageManipulation.ts
├── assets/
│   ├── icons/
│   └── luts/                # Sample LUT files
├── tests/
├── build/
├── package.json
└── electron-builder.yml
```

### Option 3: Python Desktop (Qt/Tkinter)

```
COLOR-GRADING-APP-TEST/
├── src/
│   ├── ui/                  # UI components
│   ├── core/                # Core processing
│   │   ├── color_engine.py
│   │   ├── lut_handler.py
│   │   └── image_processor.py
│   ├── utils/
│   └── main.py
├── resources/
│   ├── icons/
│   ├── luts/
│   └── themes/
├── tests/
├── requirements.txt
└── setup.py
```

---

## Technology Stack Recommendations

### For Web Application

**Frontend:**
- **Framework:** React with TypeScript or Vue.js
- **Build Tool:** Vite or Webpack
- **Canvas Library:** Fabric.js or Konva.js (for image manipulation)
- **Color Processing:**
  - `color.js` or `chroma-js` for color space conversions
  - `@reactivers/use-color-picker` for color picker UI
- **Image Processing:** Canvas API, WebGL for GPU acceleration
- **State Management:** Zustand, Redux, or Jotai
- **UI Components:** Radix UI, shadcn/ui, or Material-UI
- **Styling:** Tailwind CSS or Styled Components

**Backend:**
- **Framework:** FastAPI (Python) or Express.js (Node.js)
- **Image Processing:**
  - Python: Pillow, OpenCV, NumPy, scikit-image
  - Node.js: Sharp, Jimp
- **LUT Processing:** Custom parser or existing libraries
- **Database:** PostgreSQL or MongoDB (for saving presets)
- **File Storage:** Local filesystem or S3-compatible storage

### For Desktop Application

**Electron:**
- TypeScript + React/Vue for renderer
- Node.js for main process
- Sharp for image processing
- electron-builder for packaging

**Python Desktop:**
- PyQt5/PyQt6 or PySide6 for GUI
- Pillow + OpenCV for processing
- NumPy for numerical operations
- PyInstaller for distribution

---

## Development Workflows

### Initial Setup (First Time Contributors)

1. **Choose Technology Stack**
   - Decide on web vs desktop
   - Select primary frameworks
   - Document decision in README.md

2. **Initialize Project**
   ```bash
   # For Node.js projects
   npm init -y
   npm install <dependencies>

   # For Python projects
   python -m venv venv
   source venv/bin/activate  # or venv\Scripts\activate on Windows
   pip install -r requirements.txt
   ```

3. **Setup Configuration Files**
   - Create `.gitignore` appropriate for tech stack
   - Setup linting (ESLint, Pylint, etc.)
   - Configure formatting (Prettier, Black, etc.)
   - Add pre-commit hooks

4. **Create Initial Structure**
   - Follow recommended project structure
   - Create placeholder files
   - Document architecture decisions

### Feature Development Workflow

1. **Before Starting:**
   - Ensure you're on the correct branch (starts with `claude/`)
   - Fetch latest changes from remote
   - Understand the feature requirements

2. **Development Process:**
   ```bash
   # Create/switch to feature branch
   git checkout -b claude/feature-name-<session-id>

   # Develop incrementally
   # - Write code
   # - Write tests
   # - Run tests locally
   # - Check linting

   # Commit regularly with clear messages
   git add <files>
   git commit -m "feat: descriptive message"
   ```

3. **Before Pushing:**
   - Run full test suite
   - Check code formatting
   - Review all changes
   - Ensure no sensitive data (API keys, secrets)

4. **Push Changes:**
   ```bash
   git push -u origin claude/feature-name-<session-id>
   ```
   - Retry up to 4 times with exponential backoff if network errors
   - Branch must start with `claude/` to avoid 403 errors

### Code Review Process

- All changes should be reviewed before merging
- Use pull requests for visibility
- Run CI/CD checks automatically
- Require passing tests before merge

---

## Coding Conventions

### General Principles

1. **Code Quality:**
   - Write clear, self-documenting code
   - Prefer descriptive names over comments
   - Keep functions small and focused (single responsibility)
   - Avoid deep nesting (max 3 levels)

2. **Security:**
   - ⚠️ **CRITICAL:** Never commit secrets, API keys, or credentials
   - Validate all user inputs
   - Sanitize file paths to prevent directory traversal
   - Use parameterized queries to prevent injection attacks
   - Implement proper CORS policies for web apps
   - Validate image file types and sizes

3. **Performance:**
   - Optimize image processing operations
   - Use Web Workers or background threads for heavy computation
   - Implement lazy loading for large images
   - Cache processed results when appropriate
   - Consider GPU acceleration for real-time processing

### Language-Specific Conventions

#### JavaScript/TypeScript

```typescript
// Use TypeScript for type safety
interface ColorAdjustment {
  brightness: number;
  contrast: number;
  saturation: number;
  hue: number;
}

// Use async/await for asynchronous operations
async function processImage(imageData: ImageData): Promise<ImageData> {
  // Implementation
}

// Prefer functional programming patterns
const adjustColors = (pixels: Uint8ClampedArray, adjustment: ColorAdjustment) => {
  return pixels.map(applyAdjustment(adjustment));
};
```

**Conventions:**
- Use PascalCase for components and classes
- Use camelCase for functions and variables
- Use UPPER_SNAKE_CASE for constants
- Use 2 spaces for indentation
- Always use semicolons
- Prefer `const` over `let`, never use `var`

#### Python

```python
"""Module docstring describing purpose."""

from typing import Tuple, Optional
import numpy as np

class ColorGrader:
    """Class for applying color grading operations."""

    def adjust_exposure(
        self,
        image: np.ndarray,
        stops: float
    ) -> np.ndarray:
        """
        Adjust image exposure.

        Args:
            image: Input image as numpy array
            stops: Exposure adjustment in stops (-3 to +3)

        Returns:
            Adjusted image as numpy array
        """
        # Implementation
        pass
```

**Conventions:**
- Use snake_case for functions and variables
- Use PascalCase for classes
- Use UPPER_SNAKE_CASE for constants
- Use 4 spaces for indentation
- Follow PEP 8 style guide
- Use type hints for function signatures
- Write docstrings for all public functions/classes

### File Naming

- **Components:** PascalCase - `ColorPicker.tsx`, `ImageCanvas.tsx`
- **Utilities:** camelCase - `colorUtils.ts`, `lutParser.ts`
- **Python modules:** snake_case - `color_processor.py`, `lut_handler.py`
- **Tests:** Match source file with `.test` or `.spec` suffix
  - `ColorPicker.test.tsx`
  - `test_color_processor.py`

### Comment Guidelines

```typescript
// ❌ Bad: Obvious comment
// Increment counter
counter++;

// ✅ Good: Explains WHY
// Compensate for sRGB gamma correction before linear interpolation
const linearValue = Math.pow(srgbValue / 255, 2.2);

// ✅ Good: Document complex algorithms
/**
 * Applies 3D LUT transformation using trilinear interpolation.
 *
 * The LUT is organized as a 3D grid where each axis represents
 * input R, G, or B values. We interpolate between the 8 nearest
 * neighbors to get smooth color transitions.
 */
function apply3DLUT(rgb: RGB, lut: LUT3D): RGB {
  // Implementation
}
```

---

## Git Workflow

### Branch Naming

**AI Assistant Branches:**
- Format: `claude/<descriptive-name>-<session-id>`
- Example: `claude/implement-lut-loader-mi2il4ps3guk4fs9-013bqBTitj4Qw4HZEmfFkEn2`
- **CRITICAL:** Must start with `claude/` to avoid 403 errors on push

**Feature Branches:**
- Format: `feature/<feature-name>`
- Example: `feature/color-wheel-ui`

**Bug Fix Branches:**
- Format: `bugfix/<issue-description>`
- Example: `bugfix/histogram-rendering`

**Hotfix Branches:**
- Format: `hotfix/<critical-issue>`
- Example: `hotfix/crash-on-large-images`

### Commit Message Format

Follow conventional commits specification:

```
<type>(<scope>): <subject>

<body>

<footer>
```

**Types:**
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting, no logic change)
- `refactor`: Code refactoring
- `perf`: Performance improvements
- `test`: Adding or updating tests
- `chore`: Maintenance tasks, dependency updates

**Examples:**

```bash
# Simple feature
git commit -m "feat: add color temperature adjustment slider"

# Bug fix with description
git commit -m "fix: prevent crash when loading corrupted LUT files

The LUT parser now validates file format before parsing and
returns a helpful error message instead of crashing."

# Breaking change
git commit -m "feat!: change LUT file format to JSON

BREAKING CHANGE: Legacy .cube LUT files must be converted to
the new JSON format. Use the provided migration script."
```

### Commit Best Practices

1. **Commit Often:** Make small, logical commits
2. **Atomic Commits:** Each commit should be a complete, working change
3. **Clear Messages:** Write descriptive commit messages
4. **Test Before Commit:** Ensure tests pass
5. **No Secrets:** Never commit sensitive data

### Push Retry Logic

When pushing, implement retry with exponential backoff:

```bash
# Try 1: Immediate
git push -u origin <branch-name>

# If network error, retry with delays:
# Try 2: Wait 2s
# Try 3: Wait 4s
# Try 4: Wait 8s
# Try 5: Wait 16s
```

---

## Testing Guidelines

### Test Structure

```
tests/
├── unit/                    # Unit tests
│   ├── colorProcessing.test.ts
│   └── lutParser.test.ts
├── integration/             # Integration tests
│   └── imageProcessingPipeline.test.ts
└── e2e/                     # End-to-end tests
    └── fullWorkflow.test.ts
```

### Testing Principles

1. **Test Coverage:**
   - Aim for 80%+ code coverage
   - Test all public APIs
   - Test error conditions
   - Test edge cases

2. **Test Types:**
   - **Unit Tests:** Test individual functions/components
   - **Integration Tests:** Test component interactions
   - **E2E Tests:** Test full user workflows
   - **Visual Regression Tests:** For color grading accuracy

3. **What to Test:**
   - Color transformation accuracy
   - LUT parsing and application
   - Image loading and saving
   - User input validation
   - Error handling
   - Performance (large images)

### Test Examples

#### JavaScript/TypeScript (Jest/Vitest)

```typescript
describe('ColorProcessor', () => {
  describe('adjustBrightness', () => {
    it('should increase brightness by specified amount', () => {
      const input = createTestImage(100, 100, [128, 128, 128]);
      const result = adjustBrightness(input, 20);

      expect(result.data[0]).toBe(148);
      expect(result.data[1]).toBe(148);
      expect(result.data[2]).toBe(148);
    });

    it('should clamp values at 255', () => {
      const input = createTestImage(100, 100, [250, 250, 250]);
      const result = adjustBrightness(input, 20);

      expect(result.data[0]).toBe(255);
    });

    it('should handle negative adjustments', () => {
      const input = createTestImage(100, 100, [128, 128, 128]);
      const result = adjustBrightness(input, -30);

      expect(result.data[0]).toBe(98);
    });
  });
});
```

#### Python (pytest)

```python
import pytest
import numpy as np
from src.core.color_engine import ColorEngine

class TestColorEngine:
    @pytest.fixture
    def engine(self):
        return ColorEngine()

    @pytest.fixture
    def test_image(self):
        # Create 100x100 gray image
        return np.ones((100, 100, 3), dtype=np.uint8) * 128

    def test_adjust_exposure_positive(self, engine, test_image):
        result = engine.adjust_exposure(test_image, stops=1.0)

        # One stop should roughly double the brightness
        assert np.mean(result) > np.mean(test_image)
        assert np.max(result) <= 255  # No clipping

    def test_adjust_exposure_negative(self, engine, test_image):
        result = engine.adjust_exposure(test_image, stops=-1.0)

        # Negative stop should reduce brightness
        assert np.mean(result) < np.mean(test_image)

    def test_adjust_exposure_clamps_values(self, engine):
        bright_image = np.ones((100, 100, 3), dtype=np.uint8) * 250
        result = engine.adjust_exposure(bright_image, stops=2.0)

        assert np.max(result) == 255
        assert np.min(result) >= 0
```

### Running Tests

```bash
# JavaScript/TypeScript
npm test                    # Run all tests
npm test -- --coverage      # With coverage
npm test -- --watch        # Watch mode

# Python
pytest                      # Run all tests
pytest --cov=src           # With coverage
pytest -v                  # Verbose output
pytest -k "test_exposure"  # Run specific tests
```

---

## AI Assistant Guidelines

### When Working on This Repository

1. **Always Use TodoWrite:**
   - Create todos for multi-step tasks
   - Update status as you progress
   - Mark completed immediately after finishing

2. **Understand Before Changing:**
   - Read relevant files before editing
   - Use Explore agent for codebase understanding
   - Check existing patterns and conventions

3. **Security First:**
   - Never commit secrets or API keys
   - Validate all user inputs
   - Check for OWASP Top 10 vulnerabilities
   - Review security implications of dependencies

4. **Test Thoroughly:**
   - Write tests for new features
   - Run existing tests before committing
   - Verify changes don't break functionality

5. **Communication:**
   - Write clear commit messages
   - Document complex logic
   - Update CLAUDE.md if workflow changes
   - Keep README.md current

### Common Tasks Checklist

#### Adding a New Feature

- [ ] Create todo list for the feature
- [ ] Research existing codebase patterns
- [ ] Design the implementation
- [ ] Write tests first (TDD approach optional but recommended)
- [ ] Implement the feature
- [ ] Ensure tests pass
- [ ] Update documentation
- [ ] Commit with clear message
- [ ] Push to branch

#### Fixing a Bug

- [ ] Reproduce the bug
- [ ] Write a failing test that demonstrates the bug
- [ ] Fix the bug
- [ ] Verify test now passes
- [ ] Check for similar issues elsewhere
- [ ] Commit with `fix:` prefix
- [ ] Push to branch

#### Refactoring

- [ ] Ensure full test coverage of code to refactor
- [ ] Make incremental changes
- [ ] Run tests after each change
- [ ] Verify behavior is unchanged
- [ ] Update documentation if needed
- [ ] Commit with `refactor:` prefix

---

## Common Tasks

### Initialize a Web Project (React + TypeScript + Vite)

```bash
# Frontend
npm create vite@latest frontend -- --template react-ts
cd frontend
npm install
npm install fabric chroma-js zustand
npm install -D @types/fabric tailwindcss postcss autoprefixer

# Backend (Python FastAPI)
mkdir backend
cd backend
python -m venv venv
source venv/bin/activate
pip install fastapi uvicorn pillow opencv-python-headless numpy
pip freeze > requirements.txt
```

### Setup Linting and Formatting

```bash
# JavaScript/TypeScript
npm install -D eslint @typescript-eslint/parser @typescript-eslint/eslint-plugin
npm install -D prettier eslint-config-prettier
npm install -D husky lint-staged

# Python
pip install black pylint mypy
```

### Create .gitignore

```bash
# Node.js
cat > .gitignore << 'EOF'
# Dependencies
node_modules/
venv/
__pycache__/
*.pyc

# Build outputs
dist/
build/
*.egg-info/

# Environment
.env
.env.local
.env.*.local

# IDE
.vscode/
.idea/
*.swp
*.swo

# OS
.DS_Store
Thumbs.db

# Logs
*.log
logs/

# Temporary files
*.tmp
*.temp
.cache/

# Test coverage
coverage/
.coverage
htmlcov/

# Secrets
secrets/
*.pem
*.key
credentials.json
EOF
```

### Setup Pre-commit Hooks

```bash
# Using husky (Node.js)
npx husky-init
npm install

# Add lint-staged
npm install -D lint-staged
```

Add to `package.json`:
```json
{
  "lint-staged": {
    "*.{ts,tsx,js,jsx}": [
      "eslint --fix",
      "prettier --write"
    ]
  }
}
```

---

## Image Processing Resources

### Color Science Fundamentals

- **Color Spaces:** RGB, HSL, HSV, LAB, XYZ
- **Gamma Correction:** sRGB uses gamma 2.2
- **White Balance:** D65 (6500K) is standard
- **Bit Depth:** 8-bit (0-255), 16-bit, float (0.0-1.0)

### LUT (Look-Up Table) Formats

- **.cube:** Standard 3D LUT format
- **.3dl:** Autodesk/Lustre format
- **.png:** Hald LUT format
- **JSON:** Custom format for web applications

### Performance Optimization

1. **Use Web Workers** for CPU-intensive tasks
2. **Use WebGL** for GPU-accelerated processing
3. **Implement caching** for processed results
4. **Lazy load** large images
5. **Use requestAnimationFrame** for smooth UI updates
6. **Debounce** slider inputs to reduce recalculation

### Useful Libraries

**JavaScript:**
- `fabric.js` - Canvas manipulation
- `chroma-js` - Color conversions
- `color-js` - Advanced color operations
- `gl-matrix` - Matrix operations for color transforms

**Python:**
- `Pillow (PIL)` - Image I/O and basic operations
- `OpenCV` - Advanced image processing
- `numpy` - Numerical operations
- `scipy` - Scientific computing
- `colour-science` - Color science library

---

## Performance Benchmarks

When implementing features, consider these performance targets:

- **Small Images (< 1MP):** Process in < 100ms
- **Medium Images (1-5MP):** Process in < 500ms
- **Large Images (5-20MP):** Process in < 2s
- **UI Responsiveness:** 60 FPS (16.67ms per frame)
- **Slider Updates:** Debounce to max 30 updates/sec

---

## Deployment Considerations

### Web Application

- **Frontend:** Deploy to Vercel, Netlify, or CloudFlare Pages
- **Backend:** Deploy to Railway, Render, or AWS Lambda
- **Storage:** Use S3 or CloudFlare R2 for user uploads
- **CDN:** Use CloudFlare or AWS CloudFront

### Desktop Application

- **Electron:** Use electron-builder for packaging
- **Python:** Use PyInstaller or cx_Freeze
- **Distribution:** GitHub Releases, auto-updater
- **Code Signing:** Required for macOS, recommended for Windows

---

## Additional Resources

### Documentation to Create

As the project grows, create these additional docs:

- `docs/API.md` - API endpoints and usage
- `docs/ARCHITECTURE.md` - System architecture
- `docs/DEVELOPMENT.md` - Development setup guide
- `docs/DEPLOYMENT.md` - Deployment instructions
- `CONTRIBUTING.md` - Contribution guidelines
- `LICENSE` - Software license (MIT, GPL, etc.)

### External Resources

- [Color Grading Basics](https://en.wikipedia.org/wiki/Color_grading)
- [LUT Format Specifications](https://www.notion.so)
- [Color Science Overview](https://www.colour-science.org/)
- [Image Processing with Python](https://opencv.org/)

---

## Version History

- **2025-11-17:** Initial CLAUDE.md creation - Empty repository state documented
  - Established recommended project structures
  - Defined coding conventions and workflows
  - Set up AI assistant guidelines

---

## Quick Reference

### Essential Commands

```bash
# Start development
npm run dev                 # Frontend
uvicorn main:app --reload  # Backend (Python)

# Run tests
npm test                    # JavaScript
pytest                      # Python

# Build for production
npm run build              # Frontend
docker build .             # Docker

# Git workflow
git checkout -b claude/<feature>-<session-id>
git add .
git commit -m "feat: description"
git push -u origin <branch-name>
```

### Key Principles

1. ✅ Test before committing
2. ✅ Write clear commit messages
3. ✅ Never commit secrets
4. ✅ Follow security best practices
5. ✅ Update documentation
6. ✅ Use TodoWrite for multi-step tasks
7. ✅ Push to branches starting with `claude/`

---

**For questions or clarifications, refer to the project README.md or consult the repository owner.**
