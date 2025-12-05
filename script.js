// script.js — theme toggle + back-to-top
document.addEventListener("DOMContentLoaded", () => {
  const body = document.body;
  const themeToggle = document.getElementById("themeToggle");
  const backToTop = document.getElementById("backToTop");

  const saved = localStorage.getItem("bellasagaram-theme");
  body.setAttribute("data-theme", saved === "dark" ? "dark" : "light");

  if (themeToggle) {
    themeToggle.addEventListener("click", () => {
      const t = body.getAttribute("data-theme") === "light" ? "dark" : "light";
      body.setAttribute("data-theme", t);
      localStorage.setItem("bellasagaram-theme", t);
    });
  }

  if (backToTop) {
    window.addEventListener("scroll", () => {
      if (window.scrollY > 200) backToTop.classList.add("show");
      else backToTop.classList.remove("show");
    });
    backToTop.addEventListener("click", () => window.scrollTo({top:0,behavior:"smooth"}));
  }
});
