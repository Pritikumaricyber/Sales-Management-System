let items = [];

function showSection(id) {
  document.querySelectorAll('.section').forEach(sec => sec.style.display = 'none');
  document.getElementById(id).style.display = 'block';
}

function addItem() {
  const name = document.getElementById('addName').value.trim();
  const price = parseInt(document.getElementById('addPrice').value);
  const quantity = parseInt(document.getElementById('addQuantity').value);

  if (!name || isNaN(price) || isNaN(quantity)) {
    alert("Please enter valid details.");
    return;
  }

  items.push({ name, price, quantity });
  alert("Item added!");
  document.getElementById('addName').value = '';
  document.getElementById('addPrice').value = '';
  document.getElementById('addQuantity').value = '';
}

function searchItem() {
  const name = document.getElementById('searchName').value.trim();
  const result = items.filter(item => item.name.toLowerCase() === name.toLowerCase());

  let output = '';
  result.forEach(item => {
    output += `<p><strong>Name:</strong> ${item.name}<br><strong>Price:</strong> ${item.price}<br><strong>Quantity:</strong> ${item.quantity}</p>`;
  });

  if (!output) output = "<p>Item not found.</p>";
  document.getElementById('searchResult').innerHTML = output;
}

function sellItem() {
  const name = document.getElementById('sellName').value.trim();
  const qty = parseInt(document.getElementById('sellQuantity').value);

  for (let i = 0; i < items.length; i++) {
    if (items[i].name.toLowerCase() === name.toLowerCase()) {
      if (items[i].quantity >= qty) {
        items[i].quantity -= qty;
        alert(`Sold ${qty} units of ${name}. Remaining: ${items[i].quantity}`);
        return;
      } else {
        alert("Not enough quantity!");
        return;
      }
    }
  }

  alert("Item not found.");
}

function showAllItems() {
  showSection('display');
  let output = '';
  items.forEach(item => {
    output += `<p><strong>Name:</strong> ${item.name}<br><strong>Price:</strong> ${item.price}<br><strong>Quantity:</strong> ${item.quantity}</p>`;
  });
  if (!output) output = "<p>No items in inventory.</p>";
  document.getElementById('allItems').innerHTML = output;
}

function saveAllItemsToFile() {
  let content = items.map(item =>
    `Name: ${item.name}, Price: ${item.price}, Quantity: ${item.quantity}`
  ).join("\n");

  const blob = new Blob([content], { type: "text/plain" });
  const link = document.createElement("a");
  link.href = URL.createObjectURL(blob);
  link.download = "inventory.txt";
  link.click();
}
