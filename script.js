// script.js

document.addEventListener("DOMContentLoaded", () => {
  const body = document.body;
  const themeToggle = document.getElementById("themeToggle");
  const backToTop = document.getElementById("backToTop");

  /* ===========================
     THEME (LIGHT / DARK)
  ============================ */

  // 1. Set initial theme from localStorage or default to light
  const savedTheme = localStorage.getItem("bellasagaram-theme");
  if (savedTheme === "dark" || savedTheme === "light") {
    body.setAttribute("data-theme", savedTheme);
  } else {
    body.setAttribute("data-theme", "light");
  }

  // 2. Theme toggle button
  if (themeToggle) {
    themeToggle.addEventListener("click", () => {
      const current = body.getAttribute("data-theme") === "light" ? "dark" : "light";
      body.setAttribute("data-theme", current);
      localStorage.setItem("bellasagaram-theme", current);
    });
  }

  /* ===========================
     BACK TO TOP BUTTON
  ============================ */

  if (backToTop) {
    // Show / hide on scroll
    window.addEventListener("scroll", () => {
      if (window.scrollY > 200) {
        backToTop.classList.add("show");
      } else {
        backToTop.classList.remove("show");
      }
    });

    // Scroll smoothly to top
    backToTop.addEventListener("click", () => {
      window.scrollTo({
        top: 0,
        behavior: "smooth",
      });
    });
  }

  /* ===========================
     SMALL SCROLL REVEAL EFFECT
     (optional – subtle animation)
  ============================ */

  const animatedSections = document.querySelectorAll(
    ".section-wrapper, .hero, .about-header"
  );

  const revealOnScroll = () => {
    const triggerBottom = window.innerHeight * 0.9;

    animatedSections.forEach((sec) => {
      const rect = sec.getBoundingClientRect();
      if (rect.top < triggerBottom) {
        sec.classList.add("visible");
      }
    });
  };

  // Add a small CSS hook: .visible
  // You can style it in CSS if you want extra animation.
  window.addEventListener("scroll", revealOnScroll);
  revealOnScroll(); // initial call
});
