function findMiscreant (people) { 
  for (const p of people) {
    if (p === "Don") { 
      return "Don";
    }
    if (p === "John") {
      return "John";
    }
  }
  return "";
}
function alertForMiscreant (people) { 
  if (findMiscreant(people) !== "")
    setOffAlarms();
}
const found = alertForMiscreant(people);
